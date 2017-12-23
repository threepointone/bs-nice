(work in progress)

## nice

css-in-reason. just because.

```reason
open Nice;

let className = css([
  Display(Flex),
  AlignItems(Center),
  Color(Red),
  Select(":hover", [Color(Blue)])
]);
```

## some nice features

* pure reason
* typed css
* glamor-style composition
* escape hatch - `Raw(key, value)`

## todo

* keyframes / animations
* font-faces
* vendor prefixing
* better types
* ~ hot reloading
* 'server' side
* benchmarks / tests
