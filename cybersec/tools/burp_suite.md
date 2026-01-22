# Setup

To run `DVWA` for learning purposes:
```sh
docker run --rm -it -p 80:80 vulnerables/web-dvwa
```

Firefox, by default, prevents us to use a proxy for `localhost (127.0.0.1)`.

To overcome it, go to `about:config` and change `network.proxy.allow_hijacking_localhost` to `true`.
