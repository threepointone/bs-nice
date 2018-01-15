/* https://github.com/rofrischmann/inline-style-prefixer/tree/master/modules/static/plugins */
/* crossfade
   cursor
   filter
   flex
   flexbox ie
   gradient
   imageset
   position
   sizing
   transition  */
open Nice;

let flex =
  fun
  | Display(Flex) =>
    List.map(
      x => Raw("display", x),
      ["-webkit-box", "-moz-box", "-ms-flexbox", "-webkit-flex", "flex"]
    )
  | Display(InlineFlex) =>
    List.map(
      x => Raw("display", x),
      [
        "-webkit-inline-box",
        "-moz-inline-box",
        "-ms-inline-flexbox",
        "-webkit-inline-flex",
        "inline-flex"
      ]
    )
  | x => [x];
/* let flexBoxIE = style => */
