open Jest;

open Expect;

open Helpers;

describe("base62", () => {
  test("should work with positive int", () =>
    expect(base62_of_int(123)) |> toEqual("1Z")
  );
  test("should work with negative int", () =>
    expect(base62_of_int(-10000)) |> toEqual("2Bi")
  );
});