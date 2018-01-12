open Jest;

open Expect;

/* open Nice; */
describe("Nice", () =>
  test("toBe", () =>
    expect(1 + 2) |> toMatchSnapshot
  )
);
