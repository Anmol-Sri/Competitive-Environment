
void recur(int one_start,int one_end,int second_start,int second_end){{
    if(one_start<=one_end and second_start<=second_end){
        mid=(one_start+second_end)/2;
        print(mid)
        c=input()
        if(c=='E'){
            return -1;
        }
        if(c=='G'){
            step=0
            opp='L'
            while(one_start<=one_end and second_start<=second_end){
                part_one_middle=one_start+int((one_end-one_start)*0.67)
                part_second_middle=second_start+int((second_end-second_start)*0.33)
                print(part_one_middle)
    
                query_two=input()
                if(query_two=='E'){
                    return -1
                elif(query_two=='G' and step==0){
                    return recur(part_one_middle+1,one_end,second_start,second_end)
                step=1
                if(query_two=='L' and opp=='G'){
                    one_end=part_one_middle-1
                if(query_two==opp and query_two=='G'){
                    one_start=part_one_middle+1
                    return recur(one_start,one_end,second_start,second_end)

                print(part_second_middle)
    
                query_three=input()
                opp=query_three
                if(query_three=='E'){
                    return -1
                elif(query_two==query_three){
                    if(query_two=='L'){
                        second_end=part_second_middle-1
                    else{
                        one_start=part_one_middle+1
                    return recur(one_start,one_end,second_start,second_end)
                elif(query_two=='L' and query_three=='G'){
                    one_end=part_one_middle-1
                    second_start=part_second_middle+1
               

        else{
            step=0
            opp='G'
            while(one_start<=one_end and second_start<=second_end){
    
    
                part_one_middle=one_start+int((one_end-one_start)*0.67)
                part_second_middle=second_start+int((second_end-second_start)*0.33)

                print(part_second_middle)
    
                query_two=input()
                if(query_two=='E'){
                    return -1
                elif(query_two=='L' and step==0){
                    return recur(one_start,one_end,second_start,part_second_middle-1)
                step=1
                if(query_two=='G' and opp=='L'){
                    second_start=part_second_middle+1
                   
                if(query_two==opp and query_two=='L'){
                    second_end=part_second_middle-1
                    return recur(one_start,one_end,second_start,second_end)


                print(part_one_middle)
    
                query_three=input()
                opp=query_three
                if(query_three=='E'){
                    return -1
                elif(query_two==query_three){
                    if(query_two=='G'){
                        one_start=part_one_middle+1
                    else{
                        second_end=part_second_middle-1
                    return recur(one_start,one_end,second_start,second_end)
                elif(query_two=='G' and query_three=='L'){
                    one_end=part_one_middle-1
                    second_start=part_second_middle+1

    if(one_start>one_end and second_start<=second_end){
        recur(second_start,(second_start+second_end)/2,(second_start+second_end)/2,second_end)
    elif(second_start>second_end and one_start<=one_end){
        recur(one_start,(one_start+one_end)/2,(one_start+one_end)/2,one_end)
}
recur(1,n/2,n/2,n) 