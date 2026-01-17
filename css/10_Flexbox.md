<!--
vim:fileencoding=utf-8:foldmethod=marker
-->

# The Basics {{{

A container can be set to be a flexbox by setting `display: flexbox;`.
This turns the container to a block-level box and turns the children into *flex items*.

The default values for flexbox (and flex items) result in:

1) Flex items display as row                    (`flex-direction: row;`)
2) They don't wrap                              (`flex-wrap: nowrap;`)
3) They don't grow to fill the container        (`flex: initial;`)
4) They line up at the start of the container   ()

The *main axis* property of a flexbox container can be set with the
`flex-direction` property. The *cross axis* is perpendicular to *main axis*.

If `flex-direction` is set to `row` or `row-reverse`, then the **row** is the *main axis* and the **column** is the *cross axis*.
If `flex-direction` is set to `column` or `column-reverse`, then the **column** is the *main axis* and the **row** is the *cross axis*.

Warning: It's generally not a good idea to use `row-reverse` or
`column-reverse` or any properties in flexbox or CSS grid that can change the
ordering of the elements. This is bad for accessability and keyboard based
navigation. This is because it only changes the visual order of the elements
and leaves the logical order unchanged. Since both screen readers and keyboard
based navigation is based on the logical ordering of the elements, this causes
problems in those cases.

The *flex items* move as a group along the *main axis*.
The *flex items* can be moved as a group or individually along the *cross axis*.

**N.B.: The default behavior of flexbox and flex items are dependent on the
writing mode of the document. That's why we don't use the terms top, bottom,
left, right for describing flexbox. Instead we use main-start, main-end,
cross-start, cross-end terms.**

}}}

# Flex Wrap {{{

The initial value of `flex-wrap` is `nowrap`. This means that the flex items
inside the flexbox will overflow if there's not enough space. Before
overflowing, flex items will try to shrink to fit inside the flexbox. They will
shrink down to the `min-content` size.

To allow the flexbox to wrap to stop overflow, we can set `flex-wrap: wrap`.

When a flex container wraps, it creates multiple flex lines. In terms of space
distribution, each line acts like a new flex container. Therefore if you are
wrapping rows, it is not possible to get something in row 2 to line up with
something above it in row 1. This is what is meant by flexbox being
one-dimensional. You can control alignment in one axis, a row or a column, not
both together as we can do in grid.

Pro Tip: You can use the `flex-flow` property to set both `flex-direction` and `flex-wrap`.

```css
.container {
    display: flex;

    flex-direction: row;
    flex-wrap: wrap;
}


.container {
    display: flex;

    flex-flow: row wrap;
}
```

The above two CSS styles are equivalent.

}}}

# Controlling Space Inside Flex Items (`flex`, `flex-shrink`, `flex-grow`, `flex-basis`)


## `flex: initial;`  {{{

Assuming our container has more space than is needed to display the items, the
items line up at the start and do not grow to fill the space. They stop growing
at their `max-content` size.

This is because the `flex` property of the flex items is initially set to `initial`.
This sets the items up with the following default values:

```css
flex-grow: 0;       /* (Items don't grow) */
flex-shrink: 1;     /* (Items can shrink smaller than their flex-basis) */
flex-basis: auto;   /* (Items have a base size of `auto`) */
```

}}}

## `flex: auto;` {{{

This is the shorthand for the following:

```css
flex-grow: 1;       /* (Items can grow larger than their flex-basis) */
flex-shrink: 1;     /* (Items can shrink smaller than their flex-bais) */
flex-basis: auto;   /* (Items have a base size of `auto`) */
```

Using `flex: auto;` will mean that items end up different sizes, as the space
that is shared between the items is shared out *after* each item is laid out as
`max-content` size. So a large item will gain more space.

}}}

## `flex: 1;` {{{

This is the shorthand for the following:

```css
flex-grow: 1;       /* (Items can grow larger than their flex-basis) */
flex-shrink: 1;     /* (Items can shrink smaller than their flex-bais) */
flex-basis: 0;   /* (Items have a base size of `auto`) */
```

Using `flex: 1;` says that all items have zero size, therefore all of the space
in the flex container is available to be distributed. As all items have a
`flex-grow` factor of 1 they all grow equally and the space is shared equally.

}}}

## Custom Growth Factors {{{

We aren't forced to use the same `flex-grow` property across all flex items as
shown above. We can use different values for each flex item.

```css
.item1 {
    flex-grow: 1;
}
.item2 {
    flex-grow: 2;
}
.item3 {
    flex-grow: 3;
}
```

}}}

# Flex Item Ordering {{{

We can use the `order` property in any flex item to change its order.

However, it's not recommended as we've stated above.

}}}

# Flexbox Space Distribution {{{

The properties which distribute space are:

1) `justify-content`: space distribution on the main axis.
2) `align-content`: space distribution on the cross axis.
3) `place-content`: a shorthand for setting both of the above properties.

Shortcut to remember:
If it's for the main axis, it starts with `justify-`.
If it's for the cross axis, it starts with `align-`.

## Space Distribution in the Main Axis (`justify-content`) {{{

The default value for `justify-content` is `flex-start`. That's why the flex
items pile up in the flex-start when there's spare space in the flex container.

The available values for `justify-content` are:

- `flex-start`
- `flex-end`
- `center`
- `space-around`
- `space-between`
- `space-evenly`

}}}

## Space Distribution in the Cross Axis (`align-content`) {{{

This distributes space between the flex lines created due to wrapping.

This uses the `align-content` property and has the initial values of `strech`.

The available values for `align-content` is the same as `justify-content`
except the additional `strech`.

}}}


## Shorthand for both (`place-content`) {{{

To set both `justify-content` and `align-content` you can use `place-content`
with one or two values. A single value will be used for both axes, if you
specify both the first is used for `align-content` and the second for
`justify-content`.

}}}

}}}
