open Jest;

open Expect;

open Nice;

let serialized_rule_cache = () =>
  Hashtbl.fold((k, v, acc) => [(k, v), ...acc], Nice.rule_cache, []);

let serialized_global_cache = () =>
  Hashtbl.fold((k, v, acc) => [(k, v), ...acc], Nice.global_cache, []);

describe("Nice", () => {
  afterEach(flush);
  test("css", () =>
    expect((css([|Display(Flex), Width(Px(23))|]), serialized_rule_cache()))
    |> toMatchSnapshot
  );
  test("nesting", () =>
    expect((
      css([|
        Display(Flex),
        Color(Red),
        MediaQuery(
          "screen",
          [|
            Display(Block),
            Color(Green),
            Select(
              ":hover",
              [|
                Color(Orange),
                FontWeight(Bold),
                Overflow(Hidden),
                Supports("(display: flex)", [|Color(Blue)|]),
                Select(
                  ":active",
                  [|Color(Red), Display(Block), Select(".ie6 &", [|Color(Blue)|])|]
                )
              |]
            )
          |]
        )
      |]),
      serialized_rule_cache()
    ))
    |> toMatchSnapshot
  );
  test("global", () => {
    global("html, body", [|Padding(Px(20))|]);
    expect(serialized_global_cache()) |> toMatchSnapshot;
  });
});
