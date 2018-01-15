open Jest;

open Expect;

open Nice;

describe("Nice", () =>
  test("toBe", () => {
    let cls = css([Display(Flex)]);
    expect(rule_cache) |> toMatchSnapshot |> ignore;
    expect(cls) |> toMatchSnapshot;
  })
);
