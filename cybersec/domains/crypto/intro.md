# Caesar's Cipher (Substitution Ciphers)

In Caesar's cipher, we replace each letter with another letter that comes a few
number of positions later in the alphabet (the alphabet wraps around in this
case). This number is called *shift*.

With a shift = 3, we get:
```
Clear Text ======> hello
Encrypted Text ==> khoor
```

Due to the fact that it replaces the letters, Caesar's cipher is also called
*substitution cipher*.

# Transposition Ciphers

In this method, we simply change theorder in which the characters appear on the
cleartext. For example, we can decide that our encryption algorithm simply
moves the letters to tthe right and wraps around. In that case:
```
Clear Text ======> pico
Encrypted Text ==> opic
```

That was a very simple kind of transposition. But, we can have a map that does
more complicated transpositions. For example, we can decide to encrypt text by
doing transpostions in chunks of 6 letters using a specified mapping.
```
Mapping:
1 ---> 3
2 ---> 6
3 ---> 2
4 ---> 1
5 ---> 5
6 ---> 4

Clear Text ===========> pico**
Encrypted Text =======> c*ip*o
```

In the above example, the `*` characters were used as paddings.

# Key Ciphers

