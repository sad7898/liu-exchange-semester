using BenchmarkTools
using Random
using Profile
using StatProfilerHTML



function f()
  lst = rand(50000)
  for i in lst
    #s = "List entry $(i)\r" # The \r makes it so the terminal isn't filled
    if i > 0.99
      s = "List entry $(i)\r" # The \r makes it so the terminal isn't filled
      print(s)
    end
  end
end



@profile f()



Profile.print()
@time f()
x = @benchmark f()
println()
println(x)

statprofilehtml()
