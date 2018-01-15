open Jest;

open Expect;

open Nice;

let serialized_rule_cache = () =>
  Hashtbl.fold((k, v, acc) => [(k, v), ...acc], Nice.rule_cache, []);

let serialized_global_cache = () =>
  Hashtbl.fold((k, v, acc) => [(k, v), ...acc], Nice.global_cache, []);

describe("Nice", () => {
  afterEach(flush);
  test("css", () => {
    let cls = css([Display(Flex), Width(Px(23))]);
    expect((cls, serialized_rule_cache())) |> toMatchSnapshot;
  });
  test("global", () => {
    global("html, body", [Padding(Px(20))]);
    expect(serialized_global_cache()) |> toMatchSnapshot;
  });
});
