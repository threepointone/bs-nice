import resolve from 'rollup-plugin-node-resolve';

export default {
  input: 'lib/es6/site/demo.js',
  output: {
    name: 'Nice',
    format: 'iife',
  },
  plugins: [resolve({})],
};
