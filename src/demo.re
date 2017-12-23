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
            Supports("(display: flex)", [Color(Blue)])
          ]
        )
      ]
    )
  ]);

Js.log(className);
