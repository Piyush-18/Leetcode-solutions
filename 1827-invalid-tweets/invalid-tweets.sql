# Write your MySQL query statement below
select tweet_id from Tweets
where not LENGTH(content)<=15;