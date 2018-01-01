let combine_pairs = (keys, values) => {
  String.concat(";", List.map( (k) => String.concat(";", List.map((v) => k ++ ":" ++ v, values)), keys))
};