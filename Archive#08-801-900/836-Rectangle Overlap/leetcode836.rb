# @param {Integer[]} rec1
# @param {Integer[]} rec2
# @return {Boolean}
def is_rectangle_overlap(rec1, rec2)
  !(rec1[2] <= rec2[0] ||   # left
    rec1[3] <= rec2[1] ||   # bottom
    rec1[0] >= rec2[2] ||   # right
    rec1[1] >= rec2[3])     # top
end