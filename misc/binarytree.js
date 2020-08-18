import { max } from './minmax.js';

/**
 * A binary tree.
 * @template T
 * @typedef {{} | { root: T, left: BinaryTree<T>, right: BinaryTree<T> }} BinaryTree
 */

/**
 * Compute the height of a binary tree.
 * @param {BinaryTree<T>} binTree
 */
export function height(binTree) {
  // Return -1 if it has no root (i.e. if it's empty)
  if (!binTree.root) return -1;
  else {
    const compare = (m, n) => m - n;
    return max(height(binTree.left), height(binTree.right), compare) + 1;
  }
}

/**
 * Traverse a binary tree in the preorder manner.
 * @param {BinaryTree<T>} binTree
 * @returns {Array<T>} The traversal path
 */
export function preorder(binTree) {
  const path = []
  if (binTree.root) {
    path.push(binTree.root);
    path.push(...preorder(binTree.left));
    path.push(...preorder(binTree.right));
  }
  return path
}

/**
 * Traverse a binary tree in the inorder manner.
 * @param {BinaryTree<T>} binTree
 * @returns {Array<T>} The traversal path
 */
export function inorder(binTree) {
  const path = []
  if (binTree.root) {
    path.push(...inorder(binTree.left));
    path.push(binTree.root);
    path.push(...inorder(binTree.right));
  }
  return path
}

/**
 * Traverse a binary tree in the postorder manner.
 * @param {BinaryTree<T>} binTree
 * @returns {Array<T>} The traversal path
 */
export function postorder(binTree) {
  const path = []
  if (binTree.root) {
    path.push(...postorder(binTree.left));
    path.push(...postorder(binTree.right));
    path.push(binTree.root);
  }
  return path
}