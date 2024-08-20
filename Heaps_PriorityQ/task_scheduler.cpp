int leastInterval (vector<char>& tasks, int n){
    priority_queue<int> pq;
    queue<pair<int,int>> q;
    //we use a queue to track how much of each task is left
    //and the next time it can be executed after its 
    //(cooldown time+ the current time elapsed)
    vector<int> counter(26,0);

    //count freq of each task and push to max heap
    for(int i = 0 ; i < tasks.size(); ++i){
        ++counter[tasks[i] - 'A'];
    }
    for(int i = 0 ; i < 26; ++i){
        if(counter[i]){
            pq.push(counter[i]);
        }
    }

    int time = 0 ; 
    //process tasks until both queue and priority queue are empty
    while(!q.empty() || !pq.empty()){
        ++time;
        if(!pq.empty()){
            if(pq.top() -1 > 0){
                q.push({pq.top() -1 , time+n});
            //push to queue after iterating one task 
            //since it is in cooldown + the next time 
            //it can be executed again (we then add it back
            //to the heap and then execute)
                pq.pop();
            }
            if(!q.empty() && q.front().second == time){
                pq.push(q.front().first);
                //add the back to heap when cooldown time over
                q.pop();
            }

       }
       return time;
    }
};