// Median of Two Sorted Arrays
// link: https://leetcode.com/problems/median-of-two-sorted-arrays/description/
func findMedianSortedArrays(_ nums1: [Int], _ nums2: [Int]) -> Double {
    var A = nums1
    var B = nums2

    if B.count < A.count {
        return findMedianSortedArrays(nums2, nums1)
    }

    let m = A.count
    let n = B.count

    var l = 0
    var r = A.count

    while l <= r {
        var i:Int = (l + r) / 2
        var j:Int = (m + n + 1) / 2 - i

        var Aleft = i == 0 ? Int.min : A[i-1]
        var Aright = i == A.count ? Int.max : A[i]
        var Bleft = j == 0 ? Int.min : B[j-1]
        var Bright = j == B.count ? Int.max : B[j]

        // Correct partition
        if Aleft <= Bright && Bleft <= Aright {
            if (m + n) % 2 == 0 {
                return (Double(max(Aleft, Bleft)) + Double(min(Aright, Bright))) / 2.0
            }
            return Double(max(Aleft, Bleft))

        }
        else if Aleft > Bright {
            r = i - 1
        }
        else {
            l = i + 1
        }
    }

    return 0.0
}
