<!--
vim:fileencoding=utf-8:foldmethod=marker
-->

# Custom Properties (aka CSS variables) Basics {{{

The simplest way to create a property is by setting a value on a new property
with a name you define.

```css
:root {
    --base-size: 1em;
}
```

**NOTE:** It's a common pattern to initialize properties on the root element,
using the `:root` selector. This makes the default values accessible anywhere
on the page, but still overrideable.

All property names must start with two dashes. This prevents you from trying to
use an existing CSS property name for a custom value.

Then, this custom property can be accessed using the `var()` function:
```css
.card-title {
    font-size: calc(2 * var(--base-size));
}

.card-body {
    font-size: var(--base-size);
}
```

}}}

# Fallbacks {{{

The `var()` function can take a second value that will be used as a fallback
value. The fallback value can even be another CSS custom property with a nested
`var()`.

```css
.my-class {
    background: var(
        --alert-variant-background,
        var(--alert-primary-background)
        );
}
```

}}}

# Invalid Values {{{

If a custom property resolves to an invalid value, for example, a value of
`1em` for the background-color property, other valid declarations on *that
element for that property* won't be used. This is because the browser can't
know if a value is invalid until after it discards other declarations when
computing a value. Instead, the used value will be an *inherited* or *initial
value*.

```css
.content {
  background-color: blue;
}

.content.invalid {
  --length: 2rem;
  background-color: var(--length);
}
```

In the above example, the `.invalid` class will not have a blue background.
Instead, it'll have a `background-color` value of `transparent`. This is
because `background-color` does not inherit, thus it will be the initial value,
which is `transparent`. 

}}}

# More Control with @property {{{

A custom property that is created by setting a value can be any type, and
inherits. For more control over a custom property, we'd have to use the
`@property` rule.

For example, the following is a similar custom property set with and without
using the `@property` rule:
```css
:root {
    --base-size: 18px;
}

@property --base-size {
    syntax: "*";
    inherits: true;
    initial-value: 18px;
}
```

The `syntax` value sets the [types of CSS
values](https://developer.mozilla.org/docs/Web/CSS/@property/syntax) that are
valid for the custom property. If we set a different type on that property,
it'll be invalid, and fallback to the initial value or an inherited value set
higher in the cascade.

**NOTE:** Take a look at the above MDN link. It's worth the while if you're
using the `@property` rule.

}}}
