# https://leetcode.com/problems/design-twitter/description/
import heapq

class Twitter:
    
    def __init__(self):
        self.followerContainer = {}
        self.tweetContainer = {}
        self.timecounter = -1

    def postTweet(self,userId,tweetId):
        if userId in self.tweetContainer:
            self.tweetContainer[userId].append([self.timecounter-1,tweetId])
        else:
            self.tweetContainer[userId] = [[self.timecounter,tweetId]]
        
        self.timecounter -= 1
            

    def follow(self, followerId, followeeId):    
        if followerId in self.followerContainer:
            self.followerContainer[followerId].add(followeeId)
        else:
            self.followerContainer[followerId] = {followeeId}


    def unfollow(self, followerId, followeeId):    
        if followerId in self.followerContainer:
            self.followerContainer[followerId].remove(followeeId)
            
        
    def getNewsFeed(self,userId):
        followees = []
        tweetlist = []        
        newsfeed = []
        
        if userId in self.followerContainer:
            followees = self.followerContainer[userId]
            for f in followees:
                followee_tweet = self.tweetContainer[f] 
                for t in followee_tweet:
                    tweetlist.append(t)
        
        if userId in self.tweetContainer:
            user_tweet = self.tweetContainer[userId]
            for t in user_tweet:
                tweetlist.append(t)
            
        if len(tweetlist) == 0:
            return []
            
        key=lambda x: x[0]
        newsfeed = [(key(i),i[1]) for i in tweetlist]

        heapq.heapify(newsfeed)
        tweetlist = []
        for i in range(min(10,len(newsfeed))):
            tweetlist.append(heapq.heappop(newsfeed)[1])

        return tweetlist

t = Twitter()
t.postTweet(1,6765)
t.postTweet(5,671)
t.postTweet(3,2868)
t.postTweet(4,8148)
t.postTweet(4,386)
t.postTweet(3,6673)
t.postTweet(3,7946)
t.postTweet(3,1445)
t.postTweet(4,4822)
t.postTweet(1,3781)
t.postTweet(4,9038)
t.postTweet(1,9643)
t.postTweet(3,5917)
t.postTweet(2,8847)
t.follow(1,3)
t.follow(1,4)
t.follow(4,2)
t.follow(4,1)
t.follow(3,2)
t.follow(3,5)
t.follow(3,1)
t.follow(2,3)
t.follow(2,1)
t.follow(2,5)
t.follow(5,1)
t.follow(5,2)


print(t.getNewsFeed(1))
print(t.getNewsFeed(2))
print(t.getNewsFeed(3))
print(t.getNewsFeed(4))
print(t.getNewsFeed(5))



        
        
