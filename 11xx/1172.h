#pragma once

#include <queue>
#include <stack>

class DinnerPlates {
    std::priority_queue<int> push_idx_{};
    int pop_end_{};
    int capacity_{};
    std::vector<std::stack<int>> stacks_{};
public:
    explicit DinnerPlates(int capacity):capacity_(capacity) {

    }

    void push(int val) {
        int idx = pop_end_;
        if (!push_idx_.empty()) {
            for (idx = push_idx_.top(); !push_idx_.empty() && idx < pop_end_ && stacks_[idx].size() == capacity_; push_idx_.pop());

            if (idx >= pop_end_ || stacks_[idx].size() >= capacity_) {
                idx = pop_end_;
            }
        }

        if (idx < stacks_.size() && stacks_[idx].size() >= capacity_) {
            ++idx;
        }
        if (idx >= stacks_.size()) {
            stacks_.emplace_back();
        }
        stacks_[idx].emplace(val);

        if (idx > pop_end_) {
            pop_end_ = idx;
        }
    }

    int pop() {
        int ret = -1;
        if (pop_end_ >= stacks_.size()) {
            return ret;
        }

        for (;pop_end_ >= 0; --pop_end_) {
            if (!stacks_[pop_end_].empty()) {
                ret = stacks_[pop_end_].top();
                stacks_[pop_end_].pop();
                return ret;
            }
        }

        if (pop_end_ < 0) {
            pop_end_ = 0;
        }

        return ret;
    }

    int popAtStack(int index) {
        if (index >= stacks_.size() || index > pop_end_) {
            return -1;
        }

        if (stacks_[index].empty()) {
            return -1;
        }

        int top = stacks_[index].top();
        stacks_[index].pop();
        push_idx_.push(index);
        return top;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */