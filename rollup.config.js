import resolve from 'rollup-plugin-node-resolve';
export default {
  input: './lib/es6/src/demo.js',
  output: {
    file: 'bundle.js',
    format: 'iife',
  },
  name: 'nice',
  plugins: [resolve({ module: true, jsnext: true })],
};
