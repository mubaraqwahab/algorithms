import { minElement, maxElement } from "./minmax.js";
import { medianOfThree } from "./medianofthree.js";
import { height, preorder, inorder, postorder } from './binarytree.js';


// TEST min, max and median of three
console.log("\nTEST min, max and median of three:\n---");

class Point {
  constructor(x, y) {
    this.x = x;
    this.y = y;
  }

  toString() {
    return `(${this.x}, ${this.y})`;
  }
}

const points = [
  new Point(10, 120),
  new Point(15, 17),
  new Point(20, 31),
];

// Compare by y property
const compare = (p, q) => p.y - q.y;

const smallest = points[minElement(points, compare)];
const largest = points[maxElement(points, compare)];
const median = medianOfThree(...points, compare);

console.log(`Given ${points} and comparing by y coord`);
console.log(`min is ${smallest}`);
console.log(`max is ${largest}`);
console.log(`median is ${median}`);


// TEST binary tree

console.log("\nTEST binary tree:\n---");

const binTree = {
  root: 'a',
  left: {
    root: 'b',
    left: {
      root: 'd',
      left: {},
      right: { root: 'g', left: {}, right: {} }
    },
    right: { root: 'e', left: {}, right: {} }
  },
  right: {
    root: 'c',
    left: { root: 'f', left: {}, right: {} },
    right: {}
  }
};

// Should be 3
console.log(`Tree height is ${height(binTree)}`);

console.log(`Preorder: ${preorder(binTree)}`);
console.log(`Inorder: ${inorder(binTree)}`);
console.log(`Postorder: ${postorder(binTree)}`);