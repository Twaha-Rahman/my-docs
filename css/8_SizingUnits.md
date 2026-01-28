<!--
vim:fileencoding=utf-8:foldmethod=marker
-->

# Numbers {{{

Numbers are unitless integers (1,2,3,100 etc) and decimals (0.1 etc).

Numbers have meaning depending on their context. For example, when defining
`line-height`, a number is representative of a ratio if we define it without a
supporting unit.
```css
p {
    font-size: 24px;
    line-height: 1.5;
}
```

In the above example, 1.5 is equal to 150% of the `p` element's *computed pixel
font size*. This means that if the `p` element has a `font-size` of 24px, the
line-height will be computed as `36px`.

**NOTE:** It's a good idea to use a unitless value for `line-height` rather
than specifying a unit. Because, `font-size` can be inherited. Defining a
unitless `line-height` keeps the `line-height` relative to the font size. This
provides a better experience than using a value with a unit. This is because
the value with the unit won't change and might look strange with certain font
sizes.

}}}


# Percentage {{{

When using a percentage in CSS, we need to know how the percentage is
calculated. For example, `width` is calculated as a percentage of the available
width in the parent element. Whenever using a percentage, always keep this fact
in your mind.

}}}

# Dimensions and Lengths {{{

If we attach a unit to a number, it becomes a *dimension*. In this context, the
unit that is attached to a number is referred to in the specifications as a
*dimension token*.

*Lengths* are dimensions that *refer to distance* and they can either be
absolute or relative.


## Absolute Lengths {{{

All *absolute lengths* resolve against the *same base*, making them predictable
wherever they're used in our CSS.

For example, if we used the `cm` unit to size an element, then it would be the
same regardless of where we used it.

**NOTE:** The *physical units*, such as `cm` and `in`, won't reliably display
at those sizes on screens due to variations in pixel sizes. Physical units are
best used for print style sheets where they will be more reliable.

The available absolute length units are:
```
cm  --> Centimeters
mm  --> Milimeters
Q   --> Quarter-milimeters
in  --> Inches
pc  --> Picas
pt  --> Points
px  --> Pixels
```

}}}

## Relative Lengths {{{

A *relative length* is calculated against a *base value*, much like a
percentage. The difference between these and percentages is that you can define
sizes based on a relevant base size, such as the default font size or window
dimensions. For example: CSS has units such as `ch` that use the font's size
metrics as a basis, and `vw` which is based on the width of the viewport (your
browser window).

Relaive units can be further divided based on their *base values*:

### Font-Size-Relative Units {{{

Some of the important units in this category:

```
em      --> Relative to the font size, that is, 1.5em will be 50% larger than the base computed font size of its parent. (Historically, the height of the capital letter "M").
rem 	--> Font size of the root element (default is 16px).

ch 	    --> Average character advance of a narrow glyph in the element's font (represented by the "0" glyph).
rch 	--> The ch value of the root element.

lh      --> Line height of the element.
rlh     --> Line lh value of the root element.
```

}}}

### Viewport-Relative Units (MDN: Default Viewport Units) {{{

Some of the important units in this category:
```
vi   ---->  1% of viewport's size in the root element's inline axis. Axis refers to writing
            modes. In horizontal writing modes like English, the inline axis is horizontal.
            In vertical writing modes like some Japanese typefaces, the inline axis runs top
            to bottom.

vb   ---->  1% of viewport's size in the root element's block axis. For the block axis, this
            would be the directionality of the language. Languages like English have a vertical
            block axis, since English language readers parse the page from top to bottom. A vertical
            writing mode has a horizontal block axis.

vmin  --->  1% of the viewport's smaller dimension.
vmax  --->  1% of the viewport's larger dimension.
```

### Alternative Viewport-Relative Units (MDN: Dynamic Viewport Units) {{{

The value of the viewport-relative units remains the same as long as the
viewport size doesn't change. However, mobile browsers commonly show or hide UI
elements to show the most content possible on small screens, without changing
the calculated size of the viewport. We can use alternatives to the
viewport-relative units to account for these changes to the visible area.

Some important units in this category:
```
lvw, lvh, lvi, lvb, lvmin, lvmax    --> lv = Large viewport; This is the viewport size when all the
                                        browser UIs are hidden.(These are the same as vw, vh,...)

svw, svh, svi, svb, svmin, svmax    --> sv = Small viewport; This is the viewport size when all
                                        the browser UIs are shown. (It's recommended to use this)

dvw, dvh, dvi, dvb, dvmin, dvmax    --> dv = Dynamic viewport; This is the actual viewport size with
                                        the browser UIs taken in to account. (Don't use this as it
                                        introduces stuttering while scrolling)
```

}}}

### Container Relative Units {{{

We can use the dimensions of an element's container as a relative basis. These
units portion up the available container space. These are useful inside of
container queries to set font sizes based on the space available.

Some important units in this category:
```
cqw   ---> 1% of the container's width.
cqh   ---> 1% of the container's height.
cqi   ---> 1% of the container's inline size.
cqb   ---> 1% of the container's block size.
cqmin ---> 1% of the container's smaller dimension.
cqmax ---> 1% of the container's larger dimension.
```

}}}

}}}

}}}

}}}

# Angle Units

TBD... 

