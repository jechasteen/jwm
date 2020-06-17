
var colors = {
    gray1: "#222222",
    gray2: "#444444",
    gray3: "#bbbbbb",
    gray4: "#eeeeee",
    cyan: "#005577",
};

var appearance = {
    border: 1,
    snap: 32,
    showbar: true,
    topbar: true,
    fonts: [ "monospace:size=10" ],
    dmenufont: "monospace:size=10",
    scheme: {
        normal: {
            fg: colors.gray3,
            bg: colors.gray1,
            border: colors.gray2
        },
        selected: {
            fg: colors.gray4,
            bg: colors.cyan,
            border: colors.cyan
        }
    }
}

var tags = ["1", "2", "3", "4", "5", "6", "7", "8", "9"];

// TODO: Rules

// TODO: Layouts

// TODO: Key bindings

// TODO: Button definitions

var config = {
    appearance: appearance,
    tags: tags,
    mfact: 0.55,
    nmaster: 1,
    honorResizeHints: true
}