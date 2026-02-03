<!--
vim:fileencoding=utf-8:foldmethod=marker
-->

# Grid Terminologies {{{

The CSS grid terminologies in a glance:

1) Grid Lines
2) Grid Tracks
3) Grid Cell
4) Gaps
5) Grid Container
6) Grid Item

## Grid Lines {{{

A grid is made out of horizontal and vertical lines. If a grid has 2 rows and 4
columns, then it will have 2 row (horizontal) lines and 5 column (vertical) lines.

The lines are numbered starting from 1. The numbering depends on the writing
mode and script direction of the component. This means that column line 1 will
be on the left in a LTR language and on the right in a RTL language (such as
Arabic).

}}}

## Grid Tracks {{{

A *grid track* is the space between two *grid lines*. A *row track* is between
two row lines and a column track is between two column lines. When we create a
grid, we create these tracks by assigning a size to them.

}}}

## Grid Cell {{{

A grid cell is the cell formed by the intersection of row and column tracks.
It's just like a cell in a spreadsheet.

}}}

## Grid Area {{{

Several grid cells together form a grid area. Grid areas are created by causing
an item to span over multiple tracks.

}}}

## Gaps {{{

Gaps are a sort of gutter or alley between the tracks. For sizing purposes
these act like a regular track. You can't place content into a a gap but you
can span grid items across it.

}}}

## Grid Container {{{

The grid container is the HTML element which has `display: grid;` applied to it.

}}}

## Grid Item {{{

A grid item is simply a direct child of a parent which has `display: grid;` applied to it.

}}}

}}}

# Rows and Columns {{{

To create a simple grid with 3 column tracks and 2 row tracks with 10px gap:
```css
.container {
    display: grid;
    grid-template-columns: 5em 100px 30%;
    grid-template-rows: 200px auto;
    gap: 10px;
}
```

When used in a track sizing context, `auto` can be thought of as being as big
as as the content.

**NOTE:** `auto` sized tracks will streach by default if there is additional
space in the grid container.

## Intrinsic Sizing Keywords {{{

The grid tracks can also use intrinsic sizing keywords:

1) `min-content`    ==> Make a track as small as it can be without the track
                        content overflowing.

2) `max-content`    ==> Make a track wide enough to display in one long
                        unbroken string. This might cause overflow as
                        strings won't wrap.

3) `fit-content()`  ==> Will behave like `max-content` until it reaches the
                        provided size. After reaching it, it'll wrap.

}}}

## The `fr` unit {{{

The `fr` unit distributes space after the items have been laid out. Therefore,
to have 3 columns with the same share of available space:
```css
.container {
    display: grid;
    grid-template-columns: 1fr 1fr 1fr;
}
```

Since the `fr` unit shares out remaining/available space, it can be combined
with a fixed size gap or fixed size tracks. To have a track with a fixed size
and another track take up the available extra space, use:
```css
.container {
    display: grid;
    grid-template-columns: 200px 1fr;
}
```

Using different `fr` unit values can be useful to distribute space in different
proportions.
```css
.container {
    display: grid;
    grid-template-columns: 1fr 2fr 3fr;
}
```

}}}

## `minmax()` function {{{

The `minmax()` function can set a minimum and a maximum size for a track.

We know that the `fr` unit shares the remaining space. So, `1fr` can be written
as `minmax(auto, 1fr);`. This way, the intrinsic size gets allocated first, and
then the remaining space gets allocated.

To force each track to have the same share of space, use: `minmax(0, 1fr);`.

}}}

## `repeat()` function {{{

The `repeat()` function can be used to repeat a provided string. For example,
to create 12 column track grid with equal columns:
```css
.container {
    display: grid;
    grid-template-columns: repeat(12, minmax(0, 1fr));
}
```

It can even be mixed with regular tracks:
```css
.container {
    display: grid;
    grid-template-columns: 200px repeat(2, 1fr 2fr) 50px;
}
```

The above example creates 6 column tracks.

}}}

## `auto-fill` and `auto-fit` keywords {{{

Let's say that we don't want to specify the number of column tracks, but
instead want to create as many as will fit in our container.

We can achieve this with the `repeat()` using `auto-fill` or `auto-fit`
keywords.

To create as many 200px column tracks as we can:
```css
.container {
    display: grid;
    grid-template-columns: repeat(auto-fill, 200px);
}
```

However, this creates empty spaces when there is more space than the tracks are
allowed to take, but isn't enough space to create a new track. To solve this,
we can use `minmax()` like so:
```css
.container {
    display: grid;
    grid-template-columns: repeat(auto-fill, minmax(200px, 1fr));
}
```

But, what if we create more grid tracks than there are grid items? In that
case, we can use the `auto-fit` keyword to reduce the sizes of those tracks
down to 0. This, in turn, allows the existing tracks to grow to fill the
remaining space.
```css
.container {
    display: grid;
    grid-template-columns: repeat(auto-fit, minmax(100, 1fr));
}
```

}}}

}}}

# Auto-placement {{{

By default, CSS grid places the grid items one per grid cell in the order they
appear in the source. For more control, we can change the following:

## Placing items in columns {{{

The default behavior of grid layout is to place items along the rows. To place
the items along the columns instead, use:
```css
.container {
    display: grid;
    grid-auto-flow: column;
}
```

**NOTE:** These values relate to the writing mode of the document. A row always
runs in the direction a sentence runs in the writing mode of the document or
component. We can change it using the `writing-mode` property.

A short description of each of the values for `writing-mode` is given below:

- `horizontal-tb` ----> The default mode for languages like English. Content
                        flows horizontally from left to right (for ltr scripts)
                        or right to left (for rtl scripts), and blocks stack
                        vertically from top to bottom.

- `vertical-rl` ------> Content flows vertically from top to bottom, and blocks
                        stack horizontally from right to left (common in
                        traditional Japanese and Chinese).

- `vertical-lr` ------> Content flows vertically from top to bottom, and blocks
                        stack horizontally from left to right.

- `sideways-rl` ------> All glyphs are set sideways toward the left, with
                        content flowing vertically from bottom to top for ltr
                        scripts.

- `sideways-lr` ------> All glyphs are set sideways toward the right, with
                        content flowing vertically from top to bottom for ltr
                        scripts.

```css
.container {
    writing-mode: horizontal-tb;
    display: grid;
    grid-auto-flow: column;
}
```

}}}

## Spanning Tracks {{{

We can have a grid item span across more than one track. For this, we use the `span` keyword:
```css
.item1 {
    grid-column-end: span 2;
}

.item2 {
    grid-column: auto / span 2;
}
```

The above two examples produce equivalent results. The second one is a shorthand. 

**Explanation:** The `span` keyword is used to tell the number of lines to span as
a value for `grid-column-end` or `grid-row-end`. In the 1st example, since no
`grid-column-start` is being specified, it has the value of `auto`.

In the 2nd example, this is done explicitly.

Take a look at the docs for `grid-column` in MDN.

}}}

## `dense` keyword {{{

An auto-placed layout with some items spanning multiple tracks may result in a
grid with some unfilled cells. This is because the default behavior of grid
layout with a fully auto-placed layout is to always progress forward. The items
will be placed according to the order they are in the source (or any
modification using the `order` property).

To fill the gaps left behind, we can use the `dense` keyword:
```css
.container {
    display: grid;
    grid-auto-flow: row dense;
}
```

**Warning:** This might result in the display becoming disconnected from the
logical order as CSS grid might take grid items that appear later to fill the
gaps in the grid.

}}}

}}}

# Placing Items {{{

The most basic way of placing things onto the grid is to place them from one
line to another. The properties that can be used to place items by line number
are:

1) `grid-column-start`
2) `grid-column-end`
3) `grid-row-start`
4) `grid-row-end`

These also have the following shorthands:

1) `grid-column`
2) `grid-row`

*TIP: The dev tools (be it Chrome or Firefox) can help visually identify the
grid lines. This is really helpful for manually placing items using grid
lines.* 

Of course, the line numbering depends on the writing mode and direction of the
component.

## Stacking Items {{{

Using line-based positoning you can place items into the same cell of the grid.
This means that you can stack items, or cause one item to partly overlap
another. Items which come later in the source wil be displayed on top of items
that come earlier. This, of course, can be changed using the `z-index`
property.

}}}

## Negative Line Nubmers {{{

When we create a grid using `grid-template-rows` and `grid-template-columns`,
we create what is know as the **explicti grid**.

Sometimes, we might have items which display outside this explicit grid. For
example, we might define column tracks and then add several rows of grid items
without ever defining row tracks. The tracks would be `auto` sized by default.
We might also place an item using `grid-column-end` that is outside of the
explicit grid defined. In both cases, CSS grid will create tracks to make the
layout work, and these tracks are referred to as the *implicit grid*.

*Most* of the time, it won't matter whether we're working with implicit or
explicit grid. However, with line-based placement we may run into the main
difference between the two.

Using negative line numbers, we can place items upto the end of the exlicit
grid. For example: `grid-column: 1 / -1;` will strech the item right across the
explicit grid.

However, this only works for the explicit grid.

}}}

## Sizing Implicit Tracks {{{

The tracks created in the implicit grid will be auto-sized by default. However,
if we want to control the sizing of the rows, we can use the `grid-auto-rows`
or `grid-auto-columns` property.
```css
.container {
    display: grid;
    grid-auto-rows: minmax(10em, auto);
}
```

}}}

}}}

# Named Grid Lines {{{

Grid lines can be named using square brackets:
```css
.container {
    display: grid;
    grid-template-columns:
        [main-start aside-start] 1fr
        [aside-end content-start] 2fr
        [content-end main-end];
}

.sidebar {
    grid-column: aside-start / aside-end;
}

.footer {
    grid-column: main-start / main-end;
}
```

}}}

# Grid Template Areas {{{

We can also name areas of the grid and place items onto those named areas:
```css
.header {
    grid-area: header;
}
.sidebar {
    grid-area: sidebar;
}
.content {
    grid-area: content;
}
.footer {
    grid-area: footer;
}

.container {
    display: grid;
    grid-template-columns: repeat(4, 1fr);
    grid-template-areas:
        "header header header header"
        "sidebar content content content"
        "sidebar footer footer footer";
}
```

There are a few rules when using `grid-template-areas`:

-   The value must be a complete grid with no empty cells
-   To span tracks repeat the name
-   The areas created by repeating the name must be rectangular and cannot be
    discontinued

To leave whitespace on the grid use one or more `.` with no whitespace between
them. For example, to leave the very first cell on the grid empty:
```css
.container {
    display: grid;
    grid-template-columns: repeat(4, 1fr);
    grid-template-areas:
        "....... header header header"
        "sidebar content content content"
        "sidebar footer footer footer";
}
```

}}}

# Shorthand Properties {{{

TBD....

}}}

# Subgrid {{{

TBD....

}}}

# Alignment

TBD....

