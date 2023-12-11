local str = "f nfwfkibi bouw sfb bfutukj uk moi wfxugux qxifk moi nfwfkibi xfwmfuk qg moi bouw wem oub pufvqkp xofuk fkp zqtiy sfmxo qk f boitg sikm mq jim f boqsiz fkp zimezkip mik vukemib tfmiz kqs tubmik xfzigettl fb u sutt qktl mitt um qkxi soik oi zimezkip rqmo moi xofuk fkp moi sfmxo sizi vubbukj oi xfttip moi xzis qg oub bouw mqjimoiz moizi sizi gqez qg moiv f rzumubo jel sfb moi xqqd qg moi bouw moi xfwmfuk fbdip ouv soizi sizi lqe moi tfbm mik vukemib fkp moi xqqd fkbsizip u sfb uk moi xqtp bmqzfji zqqv mq bitixm moi vifm gqz tekxo f bzu tfkdfk sfb moi oqebi diiwukj jel moi xfwmfuk ziwifmip oub ceibmuqk mq ouv fkp tifzkm mofm moi bzu tfkdfk sfb fm moi mqw qg moi bouw xqzzixmukj moi gtfj souxo ofp riik wem ewbupi pqsk fk ukpufk jel sfb moi ikjukiiz vfukmfukukj moi bouw bfvi ceibmuqk fkp moi ukpufk mqtp mofm moi oi sfb uk moi jikizfmqz zqqv xoixdukj moi jikizfmqz f gzikxo jel ftbq bizhip qk moi oqebi diiwukj xzis bfvi ceibmuqk fkp moi gzikxo mqtp mofm oi sfb btiiwukj fgmiz moi kujom bougm sumouk mik bixqkpb moi bvfzm xfwmfuk xfejom moi mouig soq sfb moi mouig oqs pup moi xfwmfuk gukp ouv bqezxi weaatihuttf"
local out = str
local map = {
	i = "e",
	m = "t",
	o = "h",
	f = "a",
	k = "n",
	u = "i",
	b = "s",
	q = "o",
	z = "r",
	x = "c",
	t = "l",
	s = "w",
	p = "d",
	e = "u",
	w = "p",
	j = "g",
	g = "f",
	v = "m",
	d = "k",
	l = "y",
	c = "q",
	r = "b",
	n = "j",
	a = "z",
	h = "v",
	y = "x",
}
local counter = {}
local count = 1

-- replace with new letters
for i = 1, #str do
	local c = str:sub(i,i)
	if map[c] then
		-- out[i] = map[c]
		out = out:sub(1, i - 1) .. map[c] .. out:sub(i + 1)
	end
end

-- count letters
for i = 1, #str do
	local c = str:sub(i,i)
	local counterkey = nil
	for k, v in ipairs(counter) do
		if v.letter == c then
			counterkey = k
		end
	end

	if (counter[counterkey] == nil) then
		counterkey = count
		count = count + 1
		counter[counterkey] = {letter = c, count = 0}
	end
	counter[counterkey].count = counter[counterkey].count + 1
end

table.sort(
	counter,
	function(a, b)
		return a.count > b.count
	end
)
-- table.sort(counter)
for k,v in ipairs(counter) do
	print(k, v.letter, v.count)
end

print(str)
print("\n")
print(out)

-- frequencies
--[[
12,000	Ex
9,000	Tx
8,000	Ax, Ix, Nx, Ox, Sx
6,400	Hx
6,200	Rx
4,400	Dx
4,000	Lx
3,400	Ux
3,000	Cx, Mx
2,500	Fx
2,000	Wx, Yx
1,700	Gx, Px
1,600	Bx
1,200	Vx
800	Kx
500	Qx
400	Jx, Xx
200	Z
]]

--[[
Tools
	https://www3.nd.edu/~busiforc/handouts/cryptography/letterfrequencies.html
	https://www.visca.com/regexdict/
	https://regexr.com/
]]