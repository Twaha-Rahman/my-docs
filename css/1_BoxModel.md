<!--
vim:fileencoding=utf-8:foldmethod=marker
-->

# Intrinsic vs Extrinsic Sizing

*Intrinsic Size* -> Browser decided size (more flexible, less precise)
*Intrinsic Size* -> A size that was explicitly provided (less flexible, more precise)

We can set the `width` of any box to `min-content`. The `min-content` keyword
tells the box to be only as wide as the intrinsic minimum width of its content.

Overflow happens when content is too big for the box it's in. You can manage
how an element handles overflow content using the `overflow` property.

# Box Model

All elements in CSS are simply boxes. These boxes have the following areas
(inside out):

1) Content Box
2) Padding Box
3) Border Box
4) Margin Box

## Padding Box

The *padding box* is inside the box. Thus, the box's background color is
visible in the padding box.

If the box has the appropriate overflow rules set, then the scrollbars will
appear in the *padding box*.

# Box Sizing property

The box-sizing property can be used to adjust this behavior:

1) `content-box` gives you the default CSS box-sizing behavior.

If you set an element's width to 100 pixels, then the element's content box
will be 100 pixels wide, and the width of any border or padding will be added
to the final rendered width, making the element wider than 100px.

2) `border-box` tells the browser to account for any border and padding in the
values you specify for an element's width and height.

If you set an element's width to 100 pixels, that 100 pixels will include any
border or padding you added, and the content box will shrink to absorb that
extra width. This typically makes it much easier to size elements.
