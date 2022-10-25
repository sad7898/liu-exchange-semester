macro doWhile(block, cond)
  println("__source__ ", __source__)
  println("cond ", cond)
  println("block ", block)

  quote
    $(esc(block)) #esc to escape the expression = to execute that in the macro environment 
    while !$(esc(cond))
        $(esc(block))
        println("pass")
    end
  end
end

