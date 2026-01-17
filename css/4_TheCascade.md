<!--
vim:fileencoding=utf-8:foldmethod=marker
-->

# The Cascasde {{{

`CSS` stands for *Cascading Stylesheets*. The cascade is the algorithm that is
used for solving conflicts when multiple CSS rules apply to the same HTML
element. 

The cascade algorithm is split into 4 distinct stages:

- Position and order of appearance: The order in which your CSS rules appeared

- Specificity: An algorithm which determines which CSS selector has the
strongest match

- Origin: The order of when CSS appears and where it comes from. Is it a
browser imposed style? Or CSS from an extension?

- Importance: Some CSS rules are weighted more heavily than others. Especially
with the `!important` rule.

## Position and order of appearance {{{

Styles can come from various different sources:

- `<link>` tag
- `<style>` tag
- `@import` rule
- Inline CSS defined using the `<style>` tag

If multiple sources have conflicting styles, then the style that came from the
last source will have higher priority over the others.

If there are conflicting style rules within a single source, the rule that came
last will have higher priority.

**N.B.: This multiple conflicting rule property gets used in browsers for
backwards compatability.**

```css
.my-element {
    background: pink;
    background: hotpink;
}
```

In the above CSS, the browser will render the element using `hotpink`
background if browser in question supports the new CSS color. Legacy browser
that don't support `hotpink` as a color will just ignore that line and use the
`pink` color as the background.

This might is a simple example. But, more complex backwards compatability are
maintained using this technique.

}}}

## Specificity {{{

*Specificity* is an algorithm that determines which CSS selector is the most
specific, using a weighting or scoring system to make those calculations.

It basically prioritises the more specific CSS selectors over the generic CSS
selectors.

```css
.title > h1 {
    color: blue;
}

h1 {
    color: green;
}
```

In the above example, the `<h1>` text under the `<title>` tag will be colored
`blue` even though it came before the rule that states the color should be
`green`.

}}}

## Origin {{{

The origin of the CSS is taken into account to calculate the cascade. The order
of specificity of thse origins, from least to most specific is given below:

- User Agent Styles
- Local User Styles
- Authored CSS

- Authored CSS !important
- Local User Styles !important
- User Agent Styles !important

}}}

## Importance {{{

The order of importantance, from least important to most important is given
below:

- Normal Rule Type: `font-size`, `background` or `color`
- `aninmation` rule type
- `!important` rule type
- `transition` rule type

This is why active transition and aninmations have higher importance than
normal rules.

}}}


}}}
