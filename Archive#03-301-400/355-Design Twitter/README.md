# Design Twitter

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Hash_Table](https://img.shields.io/badge/哈希表-Hash_Table-007ec6.svg) ![Heap](https://img.shields.io/badge/堆-Heap-007ec6.svg) ![Design](https://img.shields.io/badge/设计-Design-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode355-cpp-f34b7d.svg)   | 72 ms   | 20.3 Mb      |
| ![python](https://img.shields.io/badge/leetcode355-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode355-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:

1. **postTweet(userId, tweetId)**: Compose a new tweet.
2. **getNewsFeed(userId)**: Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
3. **follow(followerId, followeeId)**: Follower follows a followee.
4. **unfollow(followerId, followeeId)**: Follower unfollows a followee.

## EXAMPLE

```plain
Twitter twitter = new Twitter();

// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -> [5].
twitter.getNewsFeed(1);

// User 1 follows user 2.
twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);

// User 1 unfollows user 2.
twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1);
```

## SOLUTION

* 建立两张映射表，用户表通过 id 访问用户所发布的推的 id，推特表通过推特 id 访问推特发布时间
* 涉及到的问题最主要的是多链表的合并操作

## CODE

### C++

```cpp
class Twitter
{
    struct User { unordered_set<int> followee; list<int> tweet; };
    static const int MAX_TWEET = 10;
    int time, start;
    unordered_map<int, int> tweet_time_table;
    unordered_map<int, User> user_table;
public:
    /** Initialize your data structure here. */
    Twitter() : time(0) { user_table.clear(); }
    
    // initialize an user in table
    void init(int userId)
    {
        user_table[userId].followee.clear();
        user_table[userId].tweet.clear();
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        // find user
        if (user_table.find(userId) == user_table.end()) init(userId);
        // if reach the limit, remove the front
        if (user_table[userId].tweet.size() == MAX_TWEET)
            user_table[userId].tweet.pop_back();
        user_table[userId].tweet.push_front(tweetId);
        tweet_time_table[tweetId] = ++time;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        vector<int> ans; ans.clear();
        for (auto it = user_table[userId].tweet.begin();
            it != user_table[userId].tweet.end(); it++)
        {
            ans.push_back(*it);
        }
        for (auto followeeId : user_table[userId].followee)
        {
            if (followeeId == userId) continue;
            auto it = user_table[followeeId].tweet.begin();
            int i = 0, sz = ans.size();
            vector<int> tmp;
            // merge two list
            while (i < sz && it != user_table[followeeId].tweet.end())
            {
                if (tweet_time_table[(*it)] > tweet_time_table[ans[i]])
                {
                    tmp.push_back(*it); it++;
                }
                else tmp.push_back(ans[i++]);
                if (tmp.size() == MAX_TWEET) break;
            }
            for (; i < sz && tmp.size() < MAX_TWEET; i++)
                tmp.push_back(ans[i]);
            for (; it != user_table[followeeId].tweet.end() 
                && tmp.size() < MAX_TWEET; it++)
                tmp.push_back(*it);
            ans.assign(tmp.begin(), tmp.end());
        }
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)
    {
        if (user_table.find(followerId) == user_table.end())
            init(followerId);
        if (user_table.find(followeeId) == user_table.end())
            init(followeeId);
        user_table[followerId].followee.insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId)
    {
        user_table[followerId].followee.erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
```

### Python3

```python
```

### Ruby

```ruby
```

### Java
