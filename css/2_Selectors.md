<!--
vim:fileencoding=utf-8:foldmethod=marker
-->

# Attribute Selectors {{{

The CSS attribute selectors can be used to select HTML elements that have a
specific attribute. It can even select elements with specific attributes that
have specific values for those attributes.

```css
[data-type] {
  color: black;
}

[data-type='primary'] {
  color: red;
}
```

It can even be used to match against attribute values taking into account their
case sensivity. Use the trailing `s` for case sensitive matching and trailing
`i` for case insensitive matching.

```css
[data-username='admin' s] {
  color: red;
}

[data-username='mOcK' i] {
  color: green;
}
```

It can also match a portion of the attribute value or the beginning of the
attribute value or the ending of the attribute value.

```css
/* A href that contains "example.com" */
[href*='example.com'] {
  color: red;
}

/* A href that starts with https */
[href^='https'] {
  color: green;
}

/* A href that ends with .com */
[href$='.com'] {
  color: blue;
}
```

}}}

# Grouping Selectors {{{

Multiple selectors can used create a grouping selector.

```css
h1,
.news-container,
#news-id,
[data-news-source^="https://"] {
    color: red;
}
```

}}}

# Pseudo-classes and Pseudo-elements

Pseudo-classes allows us to select HTML elements that are in a *specific state*.

```css
a:hover {
  outline: 1px dotted green;
}

p:nth-child(even) {
  background: floralwhite;
}
```

Pseudo-elements allows us to insert new elements using CSS.

```css
.my-element::before {
  content: 'Prefix - ';
}
```

Pseudo-elements aren't limited to inserting content, though. You can also use
them to target specific parts of an element.

```css
/* Your list will now either have red dots, or red numbers */
li::marker {
  color: red;
}
```

We can use the `selection` pseudo-element to style the user highlighted text.

```css
::selection {
  background: black;
  color: white;
}
```

**The `Pseudo-element` and `Pseudo-class` selectors will be covered in details later.**

# Complex Selectors

## Descendant Combinator

Selects any child (even deeply nested ones) of the specified parent.

```css
.content-body p {
    background: yellow;
    color: black;
}
```

## Next Sibling Combinator

Selects the *immediate* sibling of the specified element. Basically, the element
that follows.

```css
.content-body p + p {
    margin-top: 10px;
}
```

## Subsequent Sibling Combinator

Selects all the siblings of the specified element. The siblings don't have to
be *immediate* siblings.

```css
.content-body p + p {
    margin-top: 10px;
}
```

## Child Combinator

Selects only the *direct* childrens of the parent. Descendants that aren't
direct children are ignored.

```css
.content-body > p {
    background: gray;
}
```

# Compound Selectors

```css
a.affiliate-links {
    color: red;
}
```

