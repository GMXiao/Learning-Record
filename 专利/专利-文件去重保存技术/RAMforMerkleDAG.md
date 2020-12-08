    Algorithm: Algorithm for grouping chunks
    Input: array of file blocks' information, bInfo;length of bInfo, length 
    Output: arrar of cut points, cutPoints
    Predefined values: restrictions for group size, Tmin and Tmax
    function blocksGrouping(bInfo,length)
        i = 1;
        preCut = 0;
        while(i<length)
            if i == preCut+1 then 
                maxPoint = bInfo[i];
                i = i + 1;
                continue;
            end if
            if i == preCut+Tmax then 
                cutPoints.add(i);
                preCut = i;
                i = i + 1;
                continue;
            end if
            if bInfo[i].value >= maxPoint.value then
                if i >= preCut + Tmin
                    cutPoint.add(i);
                    preCut = i;
                else 
                    maxPoint = bInfo[i];
                end if
            end if
            i = i + 1;
        end while
    end function