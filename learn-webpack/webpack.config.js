const path = require("path");
module.exports = {
    mode: "production",
    entry: "./src/index.js",
    module: {
        rules: [
            {
                test: /\.(png|jpg|gif)$/,  
                use: {
                    //url-loader和file-loader的区别在于如果文件的大小不超过
                    //limit指定的值的话,就会以base64的方式去写到js文件里,否则就
                    //会像file-loader一样
                    loader: 'url-loader', 
                    options: {
                        name: '[name]___[hash].[ext]',
                        outputPath: "img/",
                        limit: 1024
                    }
                }
                // use: {
                //     loader: 'file-loader',
                //     options: {
                //         name: '[name]___[hash].[ext]',
                //         outputPath: "img/",
                //     }
                // }
                
            },
            {
                test: /\.css$/,
                use: [
                    'style-loader',
                    'css-loader'
                ]
            }
        ]
    },
    output: {
        filename: "index.js",
        path: path.join(__dirname, "dist")
    }
}



// console.log(path.join(__dirname , "dist"));