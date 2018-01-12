open Nice;

let className =
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

/* let className = css([Width(Em(2.))]); */
Js.log(className);
/* global("html, body", [Display(Block), Color(Green)]); */
