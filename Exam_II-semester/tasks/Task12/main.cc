int main() {
  static_assert(is_bst<TreeNode<5, TreeNode<3, TreeNode<1>, TreeNode<4>>,
                                TreeNode<8, TreeNode<6>, TreeNode<40>>>>);
  // true

  // static_assert(
  //     is_bst<
  //         TreeNode<5,
  //             TreeNode<3,
  //                 TreeNode<1>,
  //                 TreeNode<40>
  //             >,
  //             TreeNode<8,
  //                 TreeNode<6>,
  //                 TreeNode<40>
  //             >
  //         >
  //     >
  // );
  // //false

  // static_assert(
  //     is_bst<
  //         TreeNode<'k',
  //             TreeNode<0>,
  //             TreeNode<108>
  //         >
  //     >
  // );
  // // false
}