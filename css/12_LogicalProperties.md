<!--
vim:fileencoding=utf-8:foldmethod=marker
-->

# Terminology {{{

The physical properties of top, right, bottom, and left refer to the physical
dimensions of the viewport. Logical properties, on the other hand, refer to the
edges of a box as they relate to the *flow of content*. Therefore, they can
change if the text direction or writing mode changes.

*Block flow* is the direction in which *content blocks* are placed. For
example, if there were two `<img>` elements, the block flow would determine
where the second image block would go.

*Inline flow* determines how text flows in a sentence. For example, in an
English document, text flows left to right. However, in an Arabic document,
text flows right to left.

*TIP: The language of the document can be changed by using something like
`<html lang="ar">`, for example.*

The text flows in the direction determined by the document's writing mode. This
can be changed using the `writing-mode` property. Also, it can be applied to
the entire document or to the individual elements.

}}}

# Flow Relative {{{

Historically in CSS, we could only apply properties like margin relative to the
direction of their sides. For example, `margin-top` is applied to the physical
top of the element. With *logical properties*, we can now replace `margin-top`
with `margin-block-start`.

This means that regardless of **language** and **text direction**, the *block
flow* has appropriate margin rules.

This also applies to other properties like border, padding etc.

}}}

# Sizing {{{

To prevent an element exceeding a certain width or heigh, we write CSS rules
like the following:
```css
.my-element {
    max-width: 150px;
    max-height: 100px;
}
```

But, with logical properties, it will become:
```css
.my-element {
    max-inline-size: 150px;
    max-block-size: 100px;
}
```

}}}

# Start and End {{{

The `start` and `end` logical values can be used in places where physical
values such as `left`, `right` etc were used.
```css
p {
    text-align: right;
}
```

With logical properties:
```css
p {
    text-align: end;
}
```

}}}

# Borders {{{

Adding a border and border radius to an element would look something like so:
```css
.my-element {
  border-bottom: 1px solid red;
  border-right: 1px solid red;
  border-bottom-right-radius: 1em;
}
```

With logical properties:
```css
.my-element {
  border-block-end: 1px solid red;
  border-inline-end: 1px solid red;
  border-end-end-radius: 1em;
}
```

The `border-end-end-radius` here refers to the *block end* and the *inline
end*.

}}}

# Units {{{

Logical properties bring two new units: `vi` and `vb`. A `vi` unit is 1% of the
viewport size in the inline direction. The non-logical property equivalent is
`vw`. The `vb` unit is 1% of the viewport in the block direction. The
non-logical property equivalent is `vh`.

These units will always map to the reading direction. For example, if you want
an element to take up 80% of the available inline space of a viewport, using
the `vi` unit will automatically switch that size to be top to bottom if the
writing mode is vertical.

}}}
