open Nice;

let cls1 =
  css([
    Display(Flex),
    Color(Red),
    MediaQuery(
      "screen",
      [
        Display(Block),
        Color(Green),
        Select(
          ":hover",
          [
            Color(Orange),
            FontWeight(Bold),
            Overflow(Hidden),
            Supports("(display: flex)", [Color(Blue)]),
            Select(
              ":hover",
              [Color(Red), Display(Block), Select(".ie6 &", [Color(Blue)])]
            )
          ]
        )
      ]
    )
  ]);

let cls2 = css([Width(Em(4.4))]);

global("html, body", [Color(Red)]);

/* Js.log(extract("<div class='" ++ cls2 ++ "'>sdfsdf</div>")); */
Js.log(cls1);
/* global("html, body", [Display(Block), Color(Green)]); */
