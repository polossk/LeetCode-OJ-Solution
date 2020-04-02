// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 355                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

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

void test() {}

int main() { test(); return 0; }
