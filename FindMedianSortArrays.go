package main

import (
	"fmt"
)

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	var total_size= len(nums1)+len(nums2)
	var allNum []int=make([]int,total_size)
	for i:=0;i<total_size;i++{
		var val int=0
		if i>len(nums1)-1 {
		    val=nums2[i-len(nums1)]
		}else{
		   val=nums1[i]
		}
		allNum[i]=val
		for j:=i;j>0;j--{			
			preNum:=allNum[j-1]
			currentNum:=allNum[j]
			if currentNum<preNum {
				allNum[j]=preNum
				allNum[j-1]=currentNum							}

		}
	}
	
	size:=len(allNum)
	if size>0 {
		medianNum:= size/2
		if size%2==0 {
			return (float64)(allNum[medianNum]+allNum[medianNum-1])/2
		}else{
			return float64(allNum[medianNum])
		}
	}	
	return 0.0
}

func main(){
	nums1:=[]int{}
	nums2:=[]int{1}
	fmt.Println(findMedianSortedArrays(nums1,nums2))
}
