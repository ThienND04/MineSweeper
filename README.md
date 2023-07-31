# Minesweeper

## I. Tổng quan
* Minesweeper là một trò chơi giải đố dành cho một người chơi. Trò chơi bao gồm một `baĩ mìn` là những những ô vuông có thể chứa mìn, và người chơi cần phải dựa vào những con số gợi ý để mở hết tất cả những ô vuông trống mà không kích nổ quả mìn nào. 

## II. Luật chơi
* Người chơi khởi đầu bằng một bảng các ô vuông trống thể hiện `bãi mìn`
* Khi mở một ô vuông bất kì trên bảng, nếu ô đó không may có mìn, quả mìn sẽ phát nổ, trò chơi kết thúc, người chơi thua. Nếu không có mìn, vùng các ô sẽ thể hiện số lượng mìn của 8 ô xung quanh ô đó. 
* Nếu một ô có mìn, người chơi có thể `cắm cờ` để đánh dấu. 
* Có một số `máy dò mìn` được gài ngẫu nhiên trong các ô không có mìn. Khi sử dụng máy dò mìn, sẽ tự động đánh dấu những ô có mìn ở 8 ô xung quanh vị trí được sử dụng và cả ở vị trí đó(mỗi máy dò mìn chỉ dùng được 1 lần). 
* Khi người chơi mở được hết tất cả các ô không có mìn, trò chơi kết thúc, người chơi chiến thắng. 

## III. Các thao tác
* Để mở một ô, bấm chuột trái vào ô đó.
* Để cắm cờ tại một ô, bấm chuột phải vào ô đó.
* Sau khi xung quanh một ô đã đánh dấu đủ số mìn, có thể bấm chuột giữa để mở tất cả các ô còn lại xung quanh. 
* Để dùng `máy dò mìn` chọn biểu tượng máy dò mìn rôi kích chuột trái vào ô cần dò. 