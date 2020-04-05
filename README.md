# Identicon

Github uses [identicons](https://en.wikipedia.org/wiki/Identicon) for anyone without a profile picture.<sup><a href="https://github.blog/2013-08-14-identicons/">identicons - github.blog</a></sup>

An identicon is basically a visual representation of a hash value _(of user id, email, IP address)_. But since github's identicon algorithm is not in public domain, this is a _simple C++ implementation which uses random values_ to generate an identicon.

## Samples

<img src="samples/sample_1.png" height="100" /> <img src="samples/sample_2.png" height="100" /> <img src="samples/sample_3.png" height="100" /> <img src="samples/sample_4.png" height="100" />

These are 420x420 png images representing the 5x5 identicon.

----

To compile [Identicon.cpp](Identicon.cpp) on Ubuntu:

```bash
g++ Identicon.cpp `pkg-config --cflags --libs opencv`
```
