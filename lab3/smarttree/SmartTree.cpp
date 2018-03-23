//
// Created by tbk on 21.03.2018.
//

#include "SmartTree.h"
#include <ostream>
#include <string>
#include <memory>


namespace datastructures {
    std::unique_ptr<SmartTree> CreateLeaf(int value) {
        auto leaf = std::make_unique<SmartTree>();

        return leaf;
    }

    std::unique_ptr<SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree) {

        return tree;
    }

    std::unique_ptr<SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree) {

        return tree;
    }

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out) {

    }

    std::string DumpTree(const std::unique_ptr<SmartTree> &tree) {

        return "dsd";
    }


    std::unique_ptr<SmartTree> RestoreTree(const std::string &tree){
        auto leaf = std::make_unique<SmartTree>();
        return leaf;
    }


}