project('jwm', 'c')
cc = meson.get_compiler('c')
math = cc.find_library('m', required: false)
ft2 = dependency('freetype2')
X11 = dependency('X11')
xft = dependency('xft')
fontconfig = dependency('fontconfig')

src = [
    'src/drw.c',
    'src/duktape.c',
    'src/jwm.c',
    'src/util.c'
]

executable('jwm', src, dependencies: [X11, xft, math, ft2, fontconfig])