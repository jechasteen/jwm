project('jwm', 'c', 'cpp',
        default_options: ['c_std=c11', 'cpp_std=c++11'])

cc = meson.get_compiler('c')
math = cc.find_library('m', required: false)
ft2 = dependency('freetype2')
X11 = dependency('X11')
xft = dependency('xft')
fontconfig = dependency('fontconfig')
webkit = dependency('webkit2gtk-4.0')

src = [
    'src/drw.c',
    'src/jwm.cpp',
    'src/util.c'
]

executable('jwm',
    src,
    dependencies: [
        X11, 
        xft, 
        math, 
        ft2, 
        fontconfig,
        webkit,
    ]
)