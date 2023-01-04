def solution(storey):
    answer = 0
    ele_len = len(str(storey))
    ele_cnt = storey
    
    for i in range(ele_len):
        print("1ele_cnt : ", ele_cnt)
        div = ele_cnt % 10
        
        moc = ((ele_cnt-div) // 10) % 10
        # if div == 0:
        #     answer = answer + 1
        #     break
        
        print("moc : ", moc, "div : ",div)
        
        if div == 5:
            if moc >= 5:
                answer = answer + 10-div
                ele_cnt = ele_cnt + 10-div
            else:
                answer = answer + div
                ele_cnt = ele_cnt - div
        else:
            if div > 5:
                answer = answer + 10-div
                ele_cnt = ele_cnt + 10-div
            else:
                answer = answer + div
                ele_cnt = ele_cnt - div
        
        if ele_cnt == 10:
            answer = answer + 1
            break
                
        ele_cnt = ele_cnt // 10
        
            
        print("ans : ", answer)
        
    return answer
