let isBrowser =
  [%bs.raw {| typeof window !== 'undefined' |}] === Js.true_ ? true : false;

let isTest =
  [%bs.raw {| process.env.NODE_ENV === 'test' |}] === Js.true_ ? true : false;

type position =
  | Absolute
  | Relative
  | Sticky
  | Fixed;

let string_of_position =
  fun
  | Absolute => "absolute"
  | Relative => "relative"
  | Sticky => "sticky"
  | Fixed => "fixed";

type flexDirection =
  | Row
  | RowReverse
  | Column
  | ColumnReverse;

let string_of_flexDirection =
  fun
  | Row => "row"
  | RowReverse => "row-reverse"
  | Column => "column"
  | ColumnReverse => "column-reverse";

type flexWrap =
  | Wrap
  | NoWrap;

let string_of_flexWrap =
  fun
  | Wrap => "wrap"
  | NoWrap => "nowrap";

type justifyContent =
  | FlexStart
  | FlexEnd
  | Center
  | SpaceBetween
  | SpaceAround;

let string_of_justifyContent =
  fun
  | FlexStart => "flex-start"
  | FlexEnd => "flex-end"
  | Center => "center"
  | SpaceBetween => "space-between"
  | SpaceAround => "space-around";

type alignItems =
  | FlexStart
  | FlexEnd
  | Center
  | Stretch
  | Baseline;

let string_of_alignItems =
  fun
  | FlexStart => "flex-start"
  | FlexEnd => "flex-end"
  | Center => "center"
  | Stretch => "stretch"
  | Baseline => "baseline";

type alignSelf =
  | Auto
  | FlexStart
  | FlexEnd
  | Center
  | Stretch
  | Baseline;

let string_of_alignSelf =
  fun
  | Auto => "auto"
  | FlexStart => "flex-start"
  | FlexEnd => "flex-end"
  | Center => "center"
  | Stretch => "stretch"
  | Baseline => "baseline";

type alignContent =
  | Start
  | End
  | FlexStart
  | FlexEnd
  | Left
  | Right
  | Center
  | Stretch
  | SpaceBetween
  | SpaceAround
  | Baseline
  | FirstBaseline
  | LastBaseline
  | SpaceEvenly
  | SafeCenter
  | UnsafeCenter;

let string_of_alignContent =
  fun
  | Start => "start"
  | End => "end"
  | FlexStart => "flex-start"
  | FlexEnd => "flex-end"
  | Left => "left"
  | Right => "right"
  | Center => "center"
  | Stretch => "stretch"
  | SpaceBetween => "space-between"
  | SpaceAround => "space-around"
  | Baseline => "baseline"
  | FirstBaseline => "first baseline"
  | LastBaseline => "last baseline"
  | SpaceEvenly => "space-evenly"
  | SafeCenter => "safe-center"
  | UnsafeCenter => "unsafe-center";

type overflow =
  | Visible
  | Hidden
  | Scroll;

let string_of_overflow =
  fun
  | Visible => "visible"
  | Hidden => "hidden"
  | Scroll => "scroll";

type display =
  | None_
  | Block
  | Inline
  | InlineBlock
  | InlineFlex
  | Flex;

let string_of_display =
  fun
  | None_ => "none"
  | Flex => "flex"
  | Block => "block"
  | Inline => "inline"
  | InlineBlock => "inline-block"
  | InlineFlex => "inline-block";

type dimension =
  | Px(int)
  | Em(float)
  | Percent(float)
  | Calc(string);

let string_of_dimension =
  fun
  | Px(x) => {j|$(x)px|j}
  | Em(x) => {j|$(x)em|j}
  | Percent(x) => {j|$(x)%|j}
  | Calc(x) => "calc(" ++ x ++ ")";

type flexBasis =
  | Auto
  | MaxContent
  | MinContent
  | FitContent
  | Content;

let string_of_flexBasis =
  fun
  | Auto => "auto"
  | MaxContent => "max-content"
  | MinContent => "min-content"
  | FitContent => "fit-content"
  | Content => "content";

type angle =
  | Deg(float)
  | Rad(float);

let string_of_angle =
  fun
  | Deg(x) => {j|$(x)deg|j}
  | Rad(x) => {j|$(x)rad|j};

type transformStyle =
  | Perspective(float)
  | Rotate(angle)
  | RotateX(angle)
  | RotateY(angle)
  | RotateZ(angle)
  | Scale(float)
  | ScaleX(float)
  | ScaleY(float)
  | ScaleZ(float)
  | Translate(float, float)
  | TranslateX(float)
  | TranslateY(float)
  | TranslateZ(float)
  | SkewX(angle)
  | SkewY(angle);

let string_of_transform =
  fun
  | Perspective(float) => {j|perspective($(float))|j}
  | Rotate(angle) => "rotate(" ++ string_of_angle(angle) ++ ")"
  | RotateX(angle) => "rotateX(" ++ string_of_angle(angle) ++ ")"
  | RotateY(angle) => "rotateY(" ++ string_of_angle(angle) ++ ")"
  | RotateZ(angle) => "rotateZ(" ++ string_of_angle(angle) ++ ")"
  | Scale(float) => "scale(" ++ {j|$(float)|j} ++ ")"
  | ScaleX(float) => "scaleX(" ++ {j|$(float)|j} ++ ")"
  | ScaleY(float) => "scaleY(" ++ {j|$(float)|j} ++ ")"
  | ScaleZ(float) => "scaleZ(" ++ {j|$(float)|j} ++ ")"
  | Translate(x, y) => "translate(" ++ {j|$(x)|j} ++ ", " ++ {j|$(y)|j} ++ ")"
  | TranslateX(float) => "translateX(" ++ {j|$(float)|j} ++ ")"
  | TranslateY(float) => "translateY(" ++ {j|$(float)|j} ++ ")"
  | TranslateZ(float) => "translateZ(" ++ {j|$(float)|j} ++ ")"
  | SkewX(angle) => "skewX(" ++ string_of_angle(angle) ++ ")"
  | SkewY(angle) => "skewY(" ++ string_of_angle(angle) ++ ")";

type color =
  | RGB(int, int, int)
  | RGBa(int, int, int, float)
  | HSL(int, int, int)
  | HSLa(int, int, int, float)
  | Transparent
  | Aliceblue
  | Antiquewhite
  | Aqua
  | Aquamarine
  | Azure
  | Beige
  | Bisque
  | Black
  | Blanchedalmond
  | Blue
  | Blueviolet
  | Brown
  | Burlywood
  | Cadetblue
  | Chartreuse
  | Chocolate
  | Coral
  | Cornflowerblue
  | Cornsilk
  | Crimson
  | Cyan
  | Darkblue
  | Darkcyan
  | Darkgoldenrod
  | Darkgray
  | Darkgreen
  | Darkgrey
  | Darkkhaki
  | Darkmagenta
  | Darkolivegreen
  | Darkorange
  | Darkorchid
  | Darkred
  | Darksalmon
  | Darkseagreen
  | Darkslateblue
  | Darkslategrey
  | Darkturquoise
  | Darkviolet
  | Deeppink
  | Deepskyblue
  | Dimgray
  | Dimgrey
  | Dodgerblue
  | Firebrick
  | Floralwhite
  | Forestgreen
  | Fuchsia
  | Gainsboro
  | Ghostwhite
  | Gold
  | Goldenrod
  | Gray
  | Green
  | Greenyellow
  | Grey
  | Honeydew
  | Hotpink
  | Indianred
  | Indigo
  | Ivory
  | Khaki
  | Lavender
  | Lavenderblush
  | Lawngreen
  | Lemonchiffon
  | Lightblue
  | Lightcoral
  | Lightcyan
  | Lightgoldenrodyellow
  | Lightgray
  | Lightgreen
  | Lightgrey
  | Lightpink
  | Lightsalmon
  | Lightseagreen
  | Lightskyblue
  | Lightslategrey
  | Lightsteelblue
  | Lightyellow
  | Lime
  | Limegreen
  | Linen
  | Magenta
  | Maroon
  | Mediumaquamarine
  | Mediumblue
  | Mediumorchid
  | Mediumpurple
  | Mediumseagreen
  | Mediumslateblue
  | Mediumspringgreen
  | Mediumturquoise
  | Mediumvioletred
  | Midnightblue
  | Mintcream
  | Mistyrose
  | Moccasin
  | Navajowhite
  | Navy
  | Oldlace
  | Olive
  | Olivedrab
  | Orange
  | Orangered
  | Orchid
  | Palegoldenrod
  | Palegreen
  | Paleturquoise
  | Palevioletred
  | Papayawhip
  | Peachpuff
  | Peru
  | Pink
  | Plum
  | Powderblue
  | Purple
  | Rebeccapurple
  | Red
  | Rosybrown
  | Royalblue
  | Saddlebrown
  | Salmon
  | Sandybrown
  | Seagreen
  | Seashell
  | Sienna
  | Silver
  | Skyblue
  | Slateblue
  | Slategray
  | Snow
  | Springgreen
  | Steelblue
  | Tan
  | Teal
  | Thistle
  | Tomato
  | Turquoise
  | Violet
  | Wheat
  | White
  | Whitesmoke
  | Yellow
  | Yellowgreen;

let string_of_color =
  fun
  | RGB(r, g, b) => {j|rgba($(r),$(g),$(b)|j}
  | RGBa(r, g, b, a) => {j|rgba($(r),$(g),$(b),$(a))|j}
  | HSL(h, s, l) => {j|hsl($(h),$(s),$(l)|j}
  | HSLa(h, s, l, a) => {j|hsla($(h),$(s),$(l),$(a)|j}
  | Transparent => "transparent"
  | Aliceblue => "aliceblue"
  | Antiquewhite => "antiquewhite"
  | Aqua => "aqua"
  | Aquamarine => "aquamarine"
  | Azure => "azure"
  | Beige => "beige"
  | Bisque => "bisque"
  | Black => "black"
  | Blanchedalmond => "blanchedalmond"
  | Blue => "blue"
  | Blueviolet => "blueviolet"
  | Brown => "brown"
  | Burlywood => "burlywood"
  | Cadetblue => "cadetblue"
  | Chartreuse => "chartreuse"
  | Chocolate => "chocolate"
  | Coral => "coral"
  | Cornflowerblue => "cornflowerblue"
  | Cornsilk => "cornsilk"
  | Crimson => "crimson"
  | Cyan => "cyan"
  | Darkblue => "darkblue"
  | Darkcyan => "darkcyan"
  | Darkgoldenrod => "darkgoldenrod"
  | Darkgray => "darkgray"
  | Darkgreen => "darkgreen"
  | Darkgrey => "darkgrey"
  | Darkkhaki => "darkkhaki"
  | Darkmagenta => "darkmagenta"
  | Darkolivegreen => "darkolivegreen"
  | Darkorange => "darkorange"
  | Darkorchid => "darkorchid"
  | Darkred => "darkred"
  | Darksalmon => "darksalmon"
  | Darkseagreen => "darkseagreen"
  | Darkslateblue => "darkslateblue"
  | Darkslategrey => "darkslategrey"
  | Darkturquoise => "darkturquoise"
  | Darkviolet => "darkviolet"
  | Deeppink => "deeppink"
  | Deepskyblue => "deepskyblue"
  | Dimgray => "dimgray"
  | Dimgrey => "dimgrey"
  | Dodgerblue => "dodgerblue"
  | Firebrick => "firebrick"
  | Floralwhite => "floralwhite"
  | Forestgreen => "forestgreen"
  | Fuchsia => "fuchsia"
  | Gainsboro => "gainsboro"
  | Ghostwhite => "ghostwhite"
  | Gold => "gold"
  | Goldenrod => "goldenrod"
  | Gray => "gray"
  | Green => "green"
  | Greenyellow => "greenyellow"
  | Grey => "grey"
  | Honeydew => "honeydew"
  | Hotpink => "hotpink"
  | Indianred => "indianred"
  | Indigo => "indigo"
  | Ivory => "ivory"
  | Khaki => "khaki"
  | Lavender => "lavender"
  | Lavenderblush => "lavenderblush"
  | Lawngreen => "lawngreen"
  | Lemonchiffon => "lemonchiffon"
  | Lightblue => "lightblue"
  | Lightcoral => "lightcoral"
  | Lightcyan => "lightcyan"
  | Lightgoldenrodyellow => "lightgoldenrodyellow"
  | Lightgray => "lightgray"
  | Lightgreen => "lightgreen"
  | Lightgrey => "lightgrey"
  | Lightpink => "lightpink"
  | Lightsalmon => "lightsalmon"
  | Lightseagreen => "lightseagreen"
  | Lightskyblue => "lightskyblue"
  | Lightslategrey => "lightslategrey"
  | Lightsteelblue => "lightsteelblue"
  | Lightyellow => "lightyellow"
  | Lime => "lime"
  | Limegreen => "limegreen"
  | Linen => "linen"
  | Magenta => "magenta"
  | Maroon => "maroon"
  | Mediumaquamarine => "mediumaquamarine"
  | Mediumblue => "mediumblue"
  | Mediumorchid => "mediumorchid"
  | Mediumpurple => "mediumpurple"
  | Mediumseagreen => "mediumseagreen"
  | Mediumslateblue => "mediumslateblue"
  | Mediumspringgreen => "mediumspringgreen"
  | Mediumturquoise => "mediumturquoise"
  | Mediumvioletred => "mediumvioletred"
  | Midnightblue => "midnightblue"
  | Mintcream => "mintcream"
  | Mistyrose => "mistyrose"
  | Moccasin => "moccasin"
  | Navajowhite => "navajowhite"
  | Navy => "navy"
  | Oldlace => "oldlace"
  | Olive => "olive"
  | Olivedrab => "olivedrab"
  | Orange => "orange"
  | Orangered => "orangered"
  | Orchid => "orchid"
  | Palegoldenrod => "palegoldenrod"
  | Palegreen => "palegreen"
  | Paleturquoise => "paleturquoise"
  | Palevioletred => "palevioletred"
  | Papayawhip => "papayawhip"
  | Peachpuff => "peachpuff"
  | Peru => "peru"
  | Pink => "pink"
  | Plum => "plum"
  | Powderblue => "powderblue"
  | Purple => "purple"
  | Rebeccapurple => "rebeccapurple"
  | Red => "red"
  | Rosybrown => "rosybrown"
  | Royalblue => "royalblue"
  | Saddlebrown => "saddlebrown"
  | Salmon => "salmon"
  | Sandybrown => "sandybrown"
  | Seagreen => "seagreen"
  | Seashell => "seashell"
  | Sienna => "sienna"
  | Silver => "silver"
  | Skyblue => "skyblue"
  | Slateblue => "slateblue"
  | Slategray => "slategray"
  | Snow => "snow"
  | Springgreen => "springgreen"
  | Steelblue => "steelblue"
  | Tan => "tan"
  | Teal => "teal"
  | Thistle => "thistle"
  | Tomato => "tomato"
  | Turquoise => "turquoise"
  | Violet => "violet"
  | Wheat => "wheat"
  | White => "white"
  | Whitesmoke => "whitesmoke"
  | Yellow => "yellow"
  | Yellowgreen => "yellowgreen";

type fontWeight =
  | Normal
  | Bold
  | W100
  | W200
  | W300
  | W400
  | W500
  | W600
  | W700
  | W800
  | W900;

let string_of_fontWeight =
  fun
  | Normal => "normal"
  | Bold => "bold"
  | W100 => "100"
  | W200 => "200"
  | W300 => "300"
  | W400 => "400"
  | W500 => "500"
  | W600 => "600"
  | W700 => "700"
  | W800 => "800"
  | W900 => "900";

type backfaceVisibilty =
  | Visible
  | Hidden;

let string_of_backfaceVisibilty =
  fun
  | Visible => "visible"
  | Hidden => "hidden";

type borderStyle =
  | Solid
  | Dotted
  | Dashed;

let string_of_borderStyle =
  fun
  | Solid => "solid"
  | Dotted => "dotted"
  | Dashed => "dashed";

type fontStyle =
  | Normal
  | Italic;

let string_of_fontStyle =
  fun
  | Normal => "normal"
  | Italic => "italic";

type fontVariant =
  | SmallCaps
  | OldStyleNums
  | LiningNums
  | TabularNums
  | ProportionalNums;

let string_of_fontVariant =
  fun
  | SmallCaps => "small-caps"
  | OldStyleNums => "old-style-nums"
  | LiningNums => "lining-nums"
  | TabularNums => "tabular-nums"
  | ProportionalNums => "proportional-nums";

type textAlign =
  | Auto
  | Left
  | Right
  | Center
  | Justify;

let string_of_textAlign =
  fun
  | Auto => "auto"
  | Left => "left"
  | Right => "right"
  | Center => "center"
  | Justify => "justify";

type textAlignVertical =
  | Auto
  | Top
  | Bottom
  | Center;

let string_of_textAlignVertical =
  fun
  | Auto => "auto"
  | Top => "top"
  | Bottom => "bottom"
  | Center => "center";

type textDecorationLine =
  | None_
  | Underline
  | LineThrough
  | UnderlineLineThrough;

let string_of_textDecorationLine =
  fun
  | None_ => "none"
  | Underline => "underline"
  | LineThrough => "line-through"
  | UnderlineLineThrough => "underline line-through";

type textDecorationStyle =
  | Solid
  | Double
  | Dotted
  | Dashed;

let string_of_textDecorationStyle =
  fun
  | Solid => "solid"
  | Double => "double"
  | Dotted => "dotted"
  | Dashed => "dashed";

type writingDirection =
  | Auto
  | Ltr
  | Rtl;

let string_of_writingDirection =
  fun
  | Auto => "auto"
  | Ltr => "ltr"
  | Rtl => "rtl";

type resizeMode =
  | Contain
  | Cover
  | Stretch
  | Center
  | Repeat;

let string_of_resizeMode =
  fun
  | Contain => "contain"
  | Cover => "cover"
  | Stretch => "stretch"
  | Center => "center"
  | Repeat => "repeat";

/* additive-symbols

   */
type style =
  /* layout styles */
  | Display(display)
  | Width(dimension)
  | Height(dimension)
  | Top(dimension)
  | Bottom(dimension)
  | Left(dimension)
  | Right(dimension)
  | MinWidth(dimension)
  | MaxWidth(dimension)
  | MinHeight(dimension)
  | MaxHeight(dimension)
  | Margin(dimension)
  | MarginVertical(dimension)
  | MarginHorizontal(dimension)
  | MarginTop(dimension)
  | MarginBottom(dimension)
  | MarginLeft(dimension)
  | MarginRight(dimension)
  | Padding(dimension)
  | PaddingVertical(dimension)
  | PaddingHorizontal(dimension)
  | PaddingTop(dimension)
  | PaddingBottom(dimension)
  | PaddingLeft(dimension)
  | PaddingRight(dimension)
  | BorderWidth(dimension)
  | BorderTopWidth(dimension)
  | BorderBottomWidth(dimension)
  | BorderLeftWidth(dimension)
  | BorderRightWidth(dimension)
  | Position(position)
  | FlexDirection(flexDirection)
  | FlexWrap(flexWrap)
  | JustifyContent(justifyContent)
  | AlignItems(alignItems)
  | AlignSelf(alignSelf)
  | AlignContent(alignContent)
  | Overflow(overflow)
  | Flex(int)
  | FlexGrow(int)
  | FlexShrink(int)
  | FlexBasisi(int)
  | FlexBasis(flexBasis)
  /* shadow styles */
  | ShadowColor(color)
  | ShadowOffset(int, int)
  | ShadowOpacity(float)
  | ShadowRadius(float)
  /* transform styles */
  | Transform(list(transformStyle))
  /* view styles */
  | BackfaceVisibilty(backfaceVisibilty)
  | BackgroundColor(color)
  | BorderColor(color)
  | BorderTopColor(color)
  | BorderBottomColor(color)
  | BorderLeftColor(color)
  | BorderRightColor(color)
  | BorderRadius(dimension)
  | BorderTopRightRadius(dimension)
  | BorderBottomLeftRadius(dimension)
  | BorderBottomRightRadius(dimension)
  | BorderTopLeftRadius(dimension)
  | BorderStyle(borderStyle)
  | Opacity(float)
  | Elevation(float)
  /* text styles */
  | Color(color)
  | FontFamily(string)
  | FontSize(float)
  | FontStyle(fontStyle)
  | FontWeight(fontWeight)
  | FontVariant(fontVariant)
  /* | TextShadowOffset(float, float) */
  | TextShadowRadius(float)
  | TextShadowColor(color)
  | LetterSpacing(float)
  | LineHeight(float)
  | TextAlign(textAlign)
  | TextAlignVertical(textAlignVertical)
  | IncludeFontPadding(bool)
  | TextDecorationLine(textDecorationLine)
  | TextDecorationColor(color)
  | WritingDirection(writingDirection)
  /* image styles */
  | ResizeMode(resizeMode)
  | TintColor(color)
  | OverlayColor(color)
  /* at rules */
  | MediaQuery(string, ruleset)
  | Supports(string, ruleset)
  /* selectors */
  | Select(string, ruleset)
  /* escape hatch */
  | Unset(string)
  | Initial(string)
  | Inherit(string)
  | Raw(string, string)
and ruleset = list(style);

let string_of_style =
  fun
  | Display(display) => "display:" ++ string_of_display(display)
  | Width(dimension) => "width:" ++ string_of_dimension(dimension)
  | Height(dimension) => "height:" ++ string_of_dimension(dimension)
  | Top(dimension) => "top:" ++ string_of_dimension(dimension)
  | Bottom(dimension) => "bottom:" ++ string_of_dimension(dimension)
  | Left(dimension) => "left:" ++ string_of_dimension(dimension)
  | Right(dimension) => "right:" ++ string_of_dimension(dimension)
  | MinWidth(dimension) => "min-width:" ++ string_of_dimension(dimension)
  | MaxWidth(dimension) => "max-width:" ++ string_of_dimension(dimension)
  | MinHeight(dimension) => "minheight:" ++ string_of_dimension(dimension)
  | MaxHeight(dimension) => "maxheight:" ++ string_of_dimension(dimension)
  | Margin(dimension) => "margin:" ++ string_of_dimension(dimension)
  | MarginVertical(dimension) =>
    "margin-vertical:" ++ string_of_dimension(dimension)
  | MarginHorizontal(dimension) =>
    "margin-horizontal:" ++ string_of_dimension(dimension)
  | MarginTop(dimension) => "margin-top:" ++ string_of_dimension(dimension)
  | MarginBottom(dimension) =>
    "margin-bottom:" ++ string_of_dimension(dimension)
  | MarginLeft(dimension) => "margin-left:" ++ string_of_dimension(dimension)
  | MarginRight(dimension) => "margin-right:" ++ string_of_dimension(dimension)
  | Padding(dimension) => "padding:" ++ string_of_dimension(dimension)
  | PaddingVertical(dimension) =>
    "padding-vertical:" ++ string_of_dimension(dimension)
  | PaddingHorizontal(dimension) =>
    "padding-horizontal:" ++ string_of_dimension(dimension)
  | PaddingTop(dimension) => "padding-top:" ++ string_of_dimension(dimension)
  | PaddingBottom(dimension) =>
    "padding-bottom:" ++ string_of_dimension(dimension)
  | PaddingLeft(dimension) => "padding-left:" ++ string_of_dimension(dimension)
  | PaddingRight(dimension) =>
    "padding-right:" ++ string_of_dimension(dimension)
  | BorderWidth(dimension) => "border-width:" ++ string_of_dimension(dimension)
  | BorderTopWidth(dimension) =>
    "border-top-width:" ++ string_of_dimension(dimension)
  | BorderBottomWidth(dimension) =>
    "border-bottom-width:" ++ string_of_dimension(dimension)
  | BorderLeftWidth(dimension) =>
    "border-left-width:" ++ string_of_dimension(dimension)
  | BorderRightWidth(dimension) =>
    "border-right-width:" ++ string_of_dimension(dimension)
  | Position(position) => "position:" ++ string_of_position(position)
  | FlexDirection(flexDirection) =>
    "flex-direction:" ++ string_of_flexDirection(flexDirection)
  | FlexWrap(flexWrap) => "flex-wrap:" ++ string_of_flexWrap(flexWrap)
  | JustifyContent(justifyContent) =>
    "justify-content:" ++ string_of_justifyContent(justifyContent)
  | AlignItems(alignItems) =>
    "align-items:" ++ string_of_alignItems(alignItems)
  | AlignSelf(alignSelf) => "align-self:" ++ string_of_alignSelf(alignSelf)
  | AlignContent(alignContent) =>
    "align-content:" ++ string_of_alignContent(alignContent)
  | Overflow(overflow) => "overflow:" ++ string_of_overflow(overflow)
  | Flex(int) => "flex:" ++ string_of_int(int)
  | FlexGrow(int) => "flex-grow:" ++ string_of_int(int)
  | FlexShrink(int) => "flex-shrink:" ++ string_of_int(int)
  | FlexBasisi(int) => "flex-basis:" ++ string_of_int(int)
  | FlexBasis(flexBasis) => "flex-basis:" ++ string_of_flexBasis(flexBasis)
  /* shadow styles */
  | ShadowColor(color) => "shadow-color:" ++ string_of_color(color)
  | ShadowOffset(width, height) =>
    "shadow-offset:" ++ string_of_int(width) ++ "," ++ string_of_int(height)
  | ShadowOpacity(float) => "shadow-opacity:" ++ {j|$(float)|j}
  | ShadowRadius(float) => "shadow-radius:" ++ {j|$(float)|j}
  /* transform styles */
  | Transform(transformStyles) =>
    "transform:"
    ++ String.concat(",", List.map(string_of_transform, transformStyles))
  /* view styles */
  | BackfaceVisibilty(backfaceVisibilty) =>
    "backface-visibilty:" ++ string_of_backfaceVisibilty(backfaceVisibilty)
  | BackgroundColor(color) => "background-color:" ++ string_of_color(color)
  | BorderColor(color) => "border-color:" ++ string_of_color(color)
  | BorderTopColor(color) => "border-top-color:" ++ string_of_color(color)
  | BorderBottomColor(color) =>
    "border-bottom-color:" ++ string_of_color(color)
  | BorderLeftColor(color) => "border-left-color:" ++ string_of_color(color)
  | BorderRightColor(color) => "border-right-color:" ++ string_of_color(color)
  | BorderRadius(dimension) =>
    "border-radius:" ++ string_of_dimension(dimension)
  | BorderTopRightRadius(dimension) =>
    "border-top-right-radius:" ++ string_of_dimension(dimension)
  | BorderBottomLeftRadius(dimension) =>
    "border-bottom-left-radius:" ++ string_of_dimension(dimension)
  | BorderBottomRightRadius(dimension) =>
    "border-bottom-right-radius:" ++ string_of_dimension(dimension)
  | BorderTopLeftRadius(dimension) =>
    "border-top-left-radius:" ++ string_of_dimension(dimension)
  | BorderStyle(borderStyle) =>
    "border-style:" ++ string_of_borderStyle(borderStyle)
  | Opacity(float) => "opacity:" ++ {j|$(float)|j}
  | Elevation(float) => "elevation:" ++ {j|$(float)|j}
  /* text styles */
  | Color(color) => "color:" ++ string_of_color(color)
  | FontFamily(string) => "font-family:" ++ string
  | FontSize(float) => "font-size:" ++ {j|$(float)|j}
  | FontStyle(fontStyle) => "font-style:" ++ string_of_fontStyle(fontStyle)
  | FontWeight(fontWeight) =>
    "font-weight:" ++ string_of_fontWeight(fontWeight)
  | FontVariant(fontVariant) =>
    "font-variant:" ++ string_of_fontVariant(fontVariant)
  /* | TextShadowOffset(width, height) => "text-shadow-offset:" ++ Printf.sprintf("%f",width) */
  | TextShadowRadius(float) => "text-shadow-radius:" ++ {j|$(float)|j}
  | TextShadowColor(color) => "text-shadow-color:" ++ string_of_color(color)
  | LetterSpacing(float) => "letter-spacing:" ++ {j|$(float)|j}
  | LineHeight(float) => "line-height:" ++ {j|$(float)|j}
  | TextAlign(textAlign) => "text-align:" ++ string_of_textAlign(textAlign)
  | TextAlignVertical(textAlignVertical) =>
    "text-align-vertical:" ++ string_of_textAlignVertical(textAlignVertical)
  | IncludeFontPadding(bool) => "includefontpadding:" ++ string_of_bool(bool)
  | TextDecorationLine(textDecorationLine) =>
    "text-decoration-line:" ++ string_of_textDecorationLine(textDecorationLine)
  | TextDecorationColor(color) =>
    "text-decoration-color:" ++ string_of_color(color)
  | WritingDirection(writingDirection) =>
    "writing-direction:" ++ string_of_writingDirection(writingDirection)
  /* image styles */
  | ResizeMode(resizeMode) => "resizemode:" ++ string_of_resizeMode(resizeMode)
  | TintColor(color) => "tintcolor:" ++ string_of_color(color)
  | OverlayColor(color) => "overlay-color" ++ string_of_color(color)
  /* escape hatch */
  | Raw(key, value) => key ++ ":" ++ value
  | Unset(string) => string ++ ":unset"
  | Initial(string) => string ++ ":initial"
  | Inherit(string) => string ++ ":inherit"
  /* should never get here  */
  | MediaQuery(_, _)
  | Select(_, _)
  | Supports(_, _) => raise(Not_found);

/* at-rules handled before they get here */
/* | _ => raise(Not_found); */
let selectorTokenizer = [%bs.re
  {|/[(),]|"(?:\\.|[^"\n])*"|'(?:\\.|[^'\n])*'|\/\*[\s\S]*?\*\//g|}
];

/* todo - rewrite in pure reason */
let splitSelector: string => array(string) = [%bs.raw
  {|
    function(selector) {
      if(selector.indexOf(',') === -1) {
        return [selector]
      }

      var indices = [], res = [], inParen = 0, o
      /*eslint-disable no-cond-assign*/
      while (o = selectorTokenizer.exec(selector)) {
      /*eslint-enable no-cond-assign*/
        switch (o[0]) {
        case '(': inParen++; break
        case ')': inParen--; break
        case ',': if (inParen) break; indices.push(o.index)
        }
      }
      for (o = indices.length; o--;){
        res.unshift(selector.slice(indices[o] + 1))
        selector = selector.slice(0, indices[o])
      }
      res.unshift(selector)
      return res
    }
    |}
];

let replace: (string, string) => string = [%bs.raw
  {|
  function(src, _with){
    return src.replace(/\&/g, _with);
  }
  |}
];

let join_selectors = (a, b) => {
  let ax =
    splitSelector(a)
    |> Array.map(a => String.contains(a, '&') ? a : "&" ++ a)
    |> Array.to_list;
  let bx =
    splitSelector(b)
    |> Array.map(b => String.contains(b, '&') ? b : "&" ++ b)
    |> Array.to_list;
  bx
  |> List.fold_left(
       (arr, b) => List.concat([arr, ax |> List.map(a => replace(b, a))]),
       []
     )
  |> String.concat(",");
};

type scope = {
  mqs: list(string),
  supps: list(string),
  selectors: list(string)
};

let string_of_scope = (scope: scope, hash: string, content: string) => {
  let prefix = ref("");
  let suffix = ref("");
  if (List.length(scope.mqs) > 0) {
    prefix := "@media " ++ String.concat(" and ", scope.mqs) ++ "{";
    suffix := suffix^ ++ "}";
  };
  if (List.length(scope.supps) > 0) {
    suffix := suffix^ ++ "}";
    prefix :=
      prefix^ ++ "@supports " ++ String.concat(" and ", scope.supps) ++ "{";
  };
  if (List.length(scope.selectors) > 0) {
    prefix :=
      prefix^
      ++ replace(List.fold_left(join_selectors, "", scope.selectors), hash);
  };
  prefix := prefix^ ++ "{";
  suffix := suffix^ ++ "}";
  prefix^ ++ content ++ suffix^;
};

let blankScope = {mqs: [], supps: [], selectors: ["&"]};

let rec walk = (decls, scope) =>
  List.fold_left(
    (acc, style) =>
      switch style {
      | MediaQuery(q, ruleset) =>
        List.concat([
          acc,
          walk(ruleset, {...scope, mqs: List.concat([scope.mqs, [q]])})
        ])
      | Supports(s, ruleset) =>
        List.concat([
          acc,
          walk(ruleset, {...scope, supps: List.concat([scope.supps, [s]])})
        ])
      | Select(p, ruleset) =>
        List.concat([
          acc,
          walk(
            ruleset,
            {...scope, selectors: List.concat([scope.selectors, [p]])}
          )
        ])
      | x => List.concat([acc, [(scope, x)]])
      },
    [],
    decls
  );

type atom = (scope, ruleset);

/* wtf is going on here */
let group = (normalized: list((scope, style))) : list(atom) => {
  let (rest, scope, styles) =
    List.fold_left(
      (
        (rest: list(atom), lastScope: scope, styles: ruleset),
        (scope: scope, style: style)
      ) =>
        lastScope === scope ?
          (rest, scope, List.concat([styles, [style]])) :
          (List.concat([rest, [(lastScope, styles)]]), scope, [style]),
      ([], blankScope, []: ruleset),
      normalized
    );
  List.concat([rest, [(scope, styles)]]);
};

let flatten = decls => group(walk(decls, blankScope));

let global_cache = Hashtbl.create(100);

let injected_cache = Hashtbl.create(100);

let rule_cache = Hashtbl.create(100);

let flush = () => {
  Hashtbl.reset(injected_cache);
  Hashtbl.reset(rule_cache);
};

/* todo - server/node  */
/* todo - server/native */
let insertRule: string => unit = [%bs.raw
  {|function(rule){
    if(typeof window === "undefined"){
      return
    }
      var tag = document.querySelector('style[data-nice]');
      if(!tag){
        tag = document.createElement('style');
        tag.setAttribute('data-nice', '');
        document.head.appendChild(tag);
      }
      if(process.env.NODE_ENV === 'production'){

      } else {
        tag.appendChild(document.createTextNode(rule));
      }
    }|}
];

let alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

let base62_of_int = int => {
  let rec fn = (n, c) =>
    switch n {
    | 0 => c
    | _ => fn(n / 62, n - 62 * (n / 62) |> String.get(alphabet) |> Char.escaped) ++ c /* todo - collect in list and concat at end */
    };
  fn(abs(int), "");
};

let insert = (nodes: list(atom), hash: string) =>
  if (Hashtbl.mem(injected_cache, hash) === false) {
    let cssRules =
      nodes
      |> List.filter(((_scope, styles)) => styles !== [])
      |> List.map(((scope, styles)) =>
           string_of_scope(
             scope,
             hash,
             String.concat(";", List.map(string_of_style, styles))
           )
         );
    if (isBrowser && ! isTest) {
      List.map(insertRule, cssRules) |> ignore;
    } else {
      Hashtbl.add(rule_cache, hash, cssRules);
    };
    Hashtbl.add(injected_cache, hash, true);
  };

let css = decls => {
  let flattened = flatten(decls);
  let className = "css-" ++ base62_of_int(Hashtbl.hash(flattened));
  insert(flattened, "." ++ className);
  className;
};

let global = (select, decls) => {
  let flattened = flatten(decls);
  let hash = ".raw-" ++ base62_of_int(Hashtbl.hash(flattened));
  if (Hashtbl.mem(injected_cache, hash) === false) {
    let cssRules =
      flattened
      |> List.filter(((_scope, styles)) => styles !== [])
      |> List.map(((scope, styles)) =>
           string_of_scope(
             scope,
             select,
             String.concat(";", List.map(string_of_style, styles))
           )
         );
    if (isBrowser && ! isTest) {
      List.map(insertRule, cssRules) |> ignore;
    } else {
      Hashtbl.add(global_cache, hash, cssRules);
    };
    Hashtbl.add(injected_cache, hash, true);
  };
};

let raw = css => {
  /*  this hash in not inserted anywhere in the css */
  let hash = ".raw-" ++ base62_of_int(Hashtbl.hash(css));
  if (Hashtbl.mem(injected_cache, hash) === false) {
    Hashtbl.add(injected_cache, hash, true);
    if (isBrowser && ! isTest) {
      insertRule(css);
    } else {
      Hashtbl.add(global_cache, hash, [css]);
    };
  };
};

let keyframes = _steps => ();

let animation = _decls => ();

let fontFace = _decls => ();

let rehydrate = _ids => ();

type extracted = {
  css: list(string),
  ids: list(string)
};

/* grep out .css-<id>, return css and ids */
let extract = _html => {css: [], ids: []};

module Presets = {
  let mobile = "(min-width:400px)";
  let phablet = "(min-width:550px)";
  let tablet = "(min-width:750px)";
  let desktop = "(min-width:1000px)";
  let hd = "(min-width:1200px)";
};
