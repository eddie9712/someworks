const express=require("express")
const app=express()
const port=10065
app.use(express.static(__dirname + '/public2'))
app.listen(10065)
