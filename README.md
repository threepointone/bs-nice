(work in progress)

## nice

css-in-reason. just because.

```reason
open Nice;

let className = css([|
  Display(Flex),
  AlignItems(Center),
  Color(Red),
  Select(":hover", [Color(Blue)])
|]);
```

## some nice features

* pure reason
* typed css
* glamor-style composition
* escape hatch - `Raw(key, value)`

## todo

* vendor prefixing
* keyframes / animations
* font-faces
* better types
* ~ hot reloading
* benchmarks / tests
