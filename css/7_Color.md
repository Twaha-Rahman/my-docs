<!--
vim:fileencoding=utf-8:foldmethod=marker
-->

# Colors

Colors in CSS can be broadly divided into 4 catagories:

1) Named Colors
2) Numeric Colors
    (a) Hex (Hexadecimal)
    (b) RGB (Red, Green, Blue)
    (c) HSL (Hue, Saturation, Color)
3) High Definition Colors
4) System Colors

## Named Colors {{{

CSS has 148 named colors like `red`, `black`, `gray`. It also has some uncommon
ones like `tomato`, `aliceblue`, `hotpink`, and `goldenrod`.

}}}

## Numeric Colors {{{

Numeric colors can also be divided into 3 catagories:

- Hex
- RGB
- HSL

### Hex {{{

In this color format the values for red, green, and blue are set using HEX
values with 2 HEX digits for each of them. For example:

```css
color: #b71540;
```

This will set the maroon color.

Also, we can also set the alpha value using another 2 HEX digits.

```css
color: #b7154080;
```

This will set the transparency to 50%.

```
Q: How does the alpha values get calculated?

Ans: Take the last 2 HEX digits. Then, convert them to their corresponding
decimal values.

Multiply the first decimal value with 16 and then add the second decimal value.
The resulting decimal value, when divided by 255 will get the alpha value
(within 0 to 1).

Example: For the HEX color #b71540BF we take the last two HEX digits 8 and 0.
By calculating using the above method, we get ((8 * 11) + 15) = 191.

Then, we divide it with 255 and get something around 0.75. So, alpha is 75%.
```
}}}

### RGB {{{

These colors are defined using the `rgb()` function using either numbers (0 to
255) or percentages (0% to 100%). For example:

```css
h1 {
    color: rgb(255 255 255);
    color: rgb(100% 100% 100%);
}
```

To set the alpha value using RGB, we either use the `/` after the RGB numeric
values or use the `rgba()` function.

```css
h1 {
    color: rgb(255 255 255 / 50%);
    color: rgb(255 255 255 / 0.5);
    color: rgba(255,255,255, 0.5);
}
```

**N.B.: The `rgba()` function is now considered legacy. Devs should use the
`rgb()` function moving forward.**

**Also, note that previously the `rgb()` function supported the comma-separated
syntax for the color values. But, it is now considered deprecated and is still
supported for backwards compatability.**

**Devs should use the space-separated syntax moving forward.**

}}}

### HSL (Hue, Saturation, Light) {{{

This format can be used by using the `hsl()` function is CSS. The values that need to be provided are:

The first value is *hue*, which describes the degree in the HSL color circle.
This value can be provided in either degree or radian or turn. If none is
explicitly used, it is implicitly assumed to be in degree. For example:

```
75
75deg

0.5rad

0.5turn
```

The second value is the *saturation*, that describes how vibrant the hue is going to be.
A saturation of 0% will appear grayscale.

The third value is the *lightness*, that describes the brightness of the color.
A saturation of 100% is always going to give the color white.

An example usage:

```css
h1 {
    background: hsl(120 25% 50%);
    background: hsl(120deg 25% 50%);
    /* The above 2 lines are equivalent. */

    background: hsl(0.5rad 25% 50%);
    background: hsl(0.5turn 25% 50%);
}
```

The alpha value can be set in the same way as it was done in RGB.

We can use the `/` and pass the alpha value as the last value either as a
percentage or the a real value between 0 to 1. 

We can also use the `hsla()` function.

```css
    color: hsl(180 100% 75% / 50%);
    color: hsl(180 100% 75% / 0.5);

    color: hsla(180, 100%, 75%, 50%);
    color: hsla(180, 100%, 75%, 0.5);
```

}}}

}}}

## High Definition Colors {{{

The CSS `color()` function lets us choose a color in a specific color space.

The first argument is the color space that you want to use.

If we want to set the alpha value, we can do so by using a `/` followed by a
value between 0 and 1.

```css
h1 {
    background: color(srgb 0.9 0.2 0.4);
    background: color(srgb 0.9 0.2 0.4 / 0.5);

    background: color(display-p3 0.9 0.2 0.4);
}
```

**Note: RGB and HSL set colors in the sRGB gamut. Newer monitors supppor larger
color gamut which can be accessed using the advanced color gamuts. For example:
`display-p3` is a gamut that supports 50% more colors than sRGB.**

### OkLab and OkLCh

}}}


