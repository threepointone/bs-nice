(work in progress)

## nice

css-in-reason. just because.

## usage

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
* glamor style composition
* escape hatch - `Raw(key, value)`

## todo

* keyframes / animations
* vendor prefixing
* ~ hot reloading
* 'server' side
* benchmarks / tests
