open Jest;

open Nice;

describe(
  "Vendor prefixes",
  () => {
    Expect.(
      test(
        "prefixes display: flex",
        () => expect(string_of_style(Display(Flex))) |> toBe("display:-webkit-flex;display:flex")
      )
    );
    Expect.(
      test(
        "prefixes flex-direction: row",
        () =>
          expect(string_of_style(FlexDirection(Row)))
          |> toBe(
               "flex-direction:row;-webkit-flex-direction:row;-ms-flex-direction:row;-webkit-box-orient:horizontal;-webkit-box-direction:normal"
             )
      )
    );
    Expect.(
      test(
        "prefixes flex-direction: column-reverse",
        () =>
          expect(string_of_style(FlexDirection(ColumnReverse)))
          |> toBe(
               "flex-direction:column-reverse;-webkit-flex-direction:column-reverse;-ms-flex-direction:column-reverse;-webkit-box-orient:vertical;-webkit-box-direction:reverse"
             )
      )
    );
    Expect.(
      test(
        "does not prefix display: block",
        () => expect(string_of_style(Display(Block))) |> toBe("display:block")
      )
    )
  }
);