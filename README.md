# jay's dwm

This is my personal fork of dwm, affectionately dubbed jwm.

In addition to using the meson build system and having started a migration to C++, I have also applied the following patches:

* [autostart](https://dwm.suckless.org/patches/autostart/)
* [systray](https://dwm.suckless.org/patches/systray/)

## Building and Installing

```shell
git clone https://github.com/jechasteen/jwm.git
cd jwm
meson build
ninja -C build
sudo meson install -C build
```

This will install the binary at `/usr/bin/jwm` and the .desktop file at `/usr/share/xsessions`

## Configuration

The autostart patch expects to find an executable script at `~/.config/jwm/autostart.sh`.
However, it is not a fatal error if the file does not exist.

Just like with dwm, jwm is configured via hacking.
I found dwm to be difficult to work with in a modern editor with a linter enabled.
My major gripe is that config.h is inserted into a point in `dwm.c` where it can call any global, but the linter can't "see" any of it.
This makes the linter complain that almost everything is undefined.

So, if you're interested in doing simple configuration, look for
    // CONFIGURATION
in `jwm.h`.

If you're interested in applying dwm patches, good luck. Sorry, I haven't even tried yet.
If you would like a patch applied, submit a pull request and I'll consider adding the patch.

## Testing

Please note: the testing script requires the `xorg-server-xephyr` package.

`./run.sh` will open a Xephyr window and then start `build/jwm`.

`./run.sh debug` will start gdb instead.
Enter `run` to begin testing.
If something fails, enter `backtrace` to get more info.
