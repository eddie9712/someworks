const express=require("express")
const gulp=require('gulp')
const sass=require('gulp-sass')
const cssmonify=require('gulp-minify-css')
const app=express()
const port=3000
app.use(express.static(__dirname + '/public2'))
app.listen(3000)
