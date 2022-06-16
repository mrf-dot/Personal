#include <stdio.h>
#include <math.h>

int
main(int argc, char **argv) {
	int eleven = 0;
	for (int i = 0; i < 8; i++) {
		eleven += pow(10, i);
		printf("%ld\n", (long) pow(eleven, 2));
	}
}



times in msec
 clock   self+sourced   self:  sourced script
 clock   elapsed:              other lines

000.010  000.010: --- NVIM STARTING ---
000.436  000.426: locale set
000.906  000.469: inits 1
000.927  000.022: window checked
006.717  005.790: parsing arguments
007.080  000.363: expanding arguments
007.120  000.040: inits 2
007.985  000.865: init highlight
007.989  000.004: waiting for UI
009.204  001.215: done waiting for UI
009.227  000.023: init screen for UI
009.259  000.032: init default mappings
009.442  000.183: init default autocommands
016.178  002.642  002.642: sourcing /home/mitchf/.config/nvim/autoload/plug.vim
030.301  000.029  000.029: sourcing /home/mitchf/.config/nvim/autoload/plugged/unicode.vim/ftdetect/unicode.vim
030.539  010.471  010.442: sourcing /usr/share/nvim/runtime/filetype.vim
030.683  000.058  000.058: sourcing /usr/share/nvim/runtime/ftplugin.vim
030.812  000.052  000.052: sourcing /usr/share/nvim/runtime/indent.vim
031.128  000.157  000.157: sourcing /usr/share/nvim/runtime/syntax/synload.vim
031.277  000.409  000.252: sourcing /usr/share/nvim/runtime/syntax/syntax.vim
032.092  022.563  008.931: sourcing /home/mitchf/.config/nvim/init.vim
032.102  000.097: sourcing vimrc file(s)
032.896  000.146  000.146: sourcing /home/mitchf/.config/nvim/autoload/plugged/coc.nvim/autoload/coc/rpc.vim
033.601  000.633  000.633: sourcing /home/mitchf/.config/nvim/autoload/plugged/coc.nvim/autoload/coc/util.vim
034.247  000.367  000.367: sourcing /home/mitchf/.config/nvim/autoload/plugged/coc.nvim/autoload/coc/client.vim
041.133  008.585  007.440: sourcing /home/mitchf/.config/nvim/autoload/plugged/coc.nvim/plugin/coc.vim
041.353  000.043  000.043: sourcing /home/mitchf/.config/nvim/autoload/plugged/goyo.vim/plugin/goyo.vim
041.656  000.177  000.177: sourcing /home/mitchf/.config/nvim/autoload/plugged/vim-renamer/plugin/renamer.vim
042.024  000.242  000.242: sourcing /home/mitchf/.config/nvim/autoload/plugged/vim-commentary/plugin/commentary.vim
043.099  000.666  000.666: sourcing /home/mitchf/.config/nvim/autoload/plugged/vimwiki/autoload/vimwiki/vars.vim
045.459  000.162  000.162: sourcing /home/mitchf/.config/nvim/autoload/plugged/vimwiki/autoload/vimwiki/u.vim
049.876  007.745  006.917: sourcing /home/mitchf/.config/nvim/autoload/plugged/vimwiki/plugin/vimwiki.vim
050.471  000.448  000.448: sourcing /home/mitchf/.config/nvim/autoload/plugged/unicode.vim/plugin/unicode.vim
050.918  000.147  000.147: sourcing /home/mitchf/.config/nvim/autoload/plugged/vim-hexedit/autoload/hexedit.vim
051.470  000.453  000.453: sourcing /home/mitchf/.config/nvim/autoload/plugged/vim-hexedit/lib/hexedit_ui.vim
051.696  000.126  000.126: sourcing /home/mitchf/.config/nvim/autoload/plugged/vim-hexedit/lib/hexkeep_ui.vim
051.902  000.124  000.124: sourcing /home/mitchf/.config/nvim/autoload/plugged/vim-hexedit/lib/hex2py_ui.vim
052.097  000.113  000.113: sourcing /home/mitchf/.config/nvim/autoload/plugged/vim-hexedit/lib/hex2c_ui.vim
052.376  001.783  000.820: sourcing /home/mitchf/.config/nvim/autoload/plugged/vim-hexedit/plugin/hexedit.vim
053.359  000.395  000.395: sourcing /usr/share/nvim/runtime/plugin/gzip.vim
053.412  000.018  000.018: sourcing /usr/share/nvim/runtime/plugin/health.vim
053.587  000.147  000.147: sourcing /usr/share/nvim/runtime/plugin/man.vim
054.584  000.380  000.380: sourcing /usr/share/nvim/runtime/pack/dist/opt/matchit/plugin/matchit.vim
054.779  001.153  000.773: sourcing /usr/share/nvim/runtime/plugin/matchit.vim
055.105  000.295  000.295: sourcing /usr/share/nvim/runtime/plugin/matchparen.vim
055.974  000.838  000.838: sourcing /usr/share/nvim/runtime/plugin/netrwPlugin.vim
056.244  000.219  000.219: sourcing /usr/share/nvim/runtime/plugin/rplugin.vim
056.405  000.130  000.130: sourcing /usr/share/nvim/runtime/plugin/shada.vim
056.479  000.029  000.029: sourcing /usr/share/nvim/runtime/plugin/spellfile.vim
056.694  000.189  000.189: sourcing /usr/share/nvim/runtime/plugin/tarPlugin.vim
056.853  000.129  000.129: sourcing /usr/share/nvim/runtime/plugin/tohtml.vim
056.904  000.023  000.023: sourcing /usr/share/nvim/runtime/plugin/tutor.vim
059.104  000.134  000.134: sourcing /usr/share/nvim/runtime/plugin/zipPlugin.vim
059.478  004.651: loading rtp plugins
059.581  000.104: loading packages
059.861  000.280: loading after plugins
059.872  000.011: inits 3
061.095  001.223: reading ShaDa
061.213  000.118: opening buffers
061.254  000.041: BufEnter autocommands
061.256  000.002: editing files in windows
061.362  000.106: VimEnter autocommands
061.365  000.003: UIEnter autocommands
061.552  000.138  000.138: sourcing /usr/share/nvim/runtime/autoload/provider/clipboard.vim
061.559  000.056: before starting main loop
061.955  000.369  000.369: sourcing /home/mitchf/.config/nvim/autoload/plugged/coc.nvim/autoload/coc/float.vim
062.295  000.368: first screen update
062.298  000.002: --- NVIM STARTED ---


times in msec
 clock   self+sourced   self:  sourced script
 clock   elapsed:              other lines

000.015  000.015: --- NVIM STARTING ---
000.433  000.418: locale set
000.904  000.471: inits 1
000.927  000.023: window checked
006.687  005.760: parsing arguments
007.021  000.334: expanding arguments
007.056  000.035: inits 2
007.949  000.892: init highlight
007.953  000.004: waiting for UI
009.184  001.232: done waiting for UI
009.199  000.015: init screen for UI
009.231  000.032: init default mappings
009.431  000.199: init default autocommands
015.911  002.545  002.545: sourcing /home/mitchf/.config/nvim/autoload/plug.vim
030.208  000.030  000.030: sourcing /home/mitchf/.config/nvim/autoload/plugged/unicode.vim/ftdetect/unicode.vim
030.448  010.641  010.611: sourcing /usr/share/nvim/runtime/filetype.vim
030.589  000.057  000.057: sourcing /usr/share/nvim/runtime/ftplugin.vim
030.720  000.054  000.054: sourcing /usr/share/nvim/runtime/indent.vim
031.007  000.132  000.132: sourcing /usr/share/nvim/runtime/syntax/synload.vim
031.169  000.397  000.265: sourcing /usr/share/nvim/runtime/syntax/syntax.vim
031.998  022.473  008.779: sourcing /home/mitchf/.config/nvim/init.vim
032.010  000.106: sourcing vimrc file(s)
032.813  000.145  000.145: sourcing /home/mitchf/.config/nvim/autoload/plugged/coc.nvim/autoload/coc/rpc.vim
033.515  000.626  000.626: sourcing /home/mitchf/.config/nvim/autoload/plugged/coc.nvim/autoload/coc/util.vim
034.168  000.374  000.374: sourcing /home/mitchf/.config/nvim/autoload/plugged/coc.nvim/autoload/coc/client.vim
038.204  005.740  004.595: sourcing /home/mitchf/.config/nvim/autoload/plugged/coc.nvim/plugin/coc.vim
038.322  000.018  000.018: sourcing /home/mitchf/.config/nvim/autoload/plugged/goyo.vim/plugin/goyo.vim
038.436  000.068  000.068: sourcing /home/mitchf/.config/nvim/autoload/plugged/vim-renamer/plugin/renamer.vim
038.562  000.082  000.082: sourcing /home/mitchf/.config/nvim/autoload/plugged/vim-commentary/plugin/commentary.vim
038.926  000.219  000.219: sourcing /home/mitchf/.config/nvim/autoload/plugged/vimwiki/autoload/vimwiki/vars.vim
039.734  000.055  000.055: sourcing /home/mitchf/.config/nvim/autoload/plugged/vimwiki/autoload/vimwiki/u.vim
041.353  002.750  002.476: sourcing /home/mitchf/.config/nvim/autoload/plugged/vimwiki/plugin/vimwiki.vim
041.595  000.164  000.164: sourcing /home/mitchf/.config/nvim/autoload/plugged/unicode.vim/plugin/unicode.vim
041.753  000.050  000.050: sourcing /home/mitchf/.config/nvim/autoload/plugged/vim-hexedit/autoload/hexedit.vim
041.926  000.138  000.138: sourcing /home/mitchf/.config/nvim/autoload/plugged/vim-hexedit/lib/hexedit_ui.vim
041.999  000.042  000.042: sourcing /home/mitchf/.config/nvim/autoload/plugged/vim-hexedit/lib/hexkeep_ui.vim
042.070  000.042  000.042: sourcing /home/mitchf/.config/nvim/autoload/plugged/vim-hexedit/lib/hex2py_ui.vim
042.137  000.039  000.039: sourcing /home/mitchf/.config/nvim/autoload/plugged/vim-hexedit/lib/hex2c_ui.vim
042.340  000.700  000.389: sourcing /home/mitchf/.config/nvim/autoload/plugged/vim-hexedit/plugin/hexedit.vim
042.721  000.140  000.140: sourcing /usr/share/nvim/runtime/plugin/gzip.vim
042.750  000.007  000.007: sourcing /usr/share/nvim/runtime/plugin/health.vim
042.813  000.052  000.052: sourcing /usr/share/nvim/runtime/plugin/man.vim
043.183  000.152  000.152: sourcing /usr/share/nvim/runtime/pack/dist/opt/matchit/plugin/matchit.vim
043.252  000.429  000.277: sourcing /usr/share/nvim/runtime/plugin/matchit.vim
043.354  000.091  000.091: sourcing /usr/share/nvim/runtime/plugin/matchparen.vim
043.664  000.301  000.301: sourcing /usr/share/nvim/runtime/plugin/netrwPlugin.vim
043.784  000.095  000.095: sourcing /usr/share/nvim/runtime/plugin/rplugin.vim
043.880  000.071  000.071: sourcing /usr/share/nvim/runtime/plugin/shada.vim
043.911  000.014  000.014: sourcing /usr/share/nvim/runtime/plugin/spellfile.vim
044.017  000.093  000.093: sourcing /usr/share/nvim/runtime/plugin/tarPlugin.vim
044.090  000.057  000.057: sourcing /usr/share/nvim/runtime/plugin/tohtml.vim
044.114  000.012  000.012: sourcing /usr/share/nvim/runtime/plugin/tutor.vim
044.263  000.114  000.114: sourcing /usr/share/nvim/runtime/plugin/zipPlugin.vim
044.643  001.635: loading rtp plugins
044.746  000.103: loading packages
045.027  000.281: loading after plugins
045.040  000.013: inits 3
045.543  000.503: reading ShaDa
045.665  000.122: opening buffers
045.707  000.042: BufEnter autocommands
045.710  000.003: editing files in windows
045.818  000.108: VimEnter autocommands
045.821  000.003: UIEnter autocommands
046.012  000.138  000.138: sourcing /usr/share/nvim/runtime/autoload/provider/clipboard.vim
046.018  000.060: before starting main loop
046.415  000.366  000.366: sourcing /home/mitchf/.config/nvim/autoload/plugged/coc.nvim/autoload/coc/float.vim
046.656  000.272: first screen update
046.659  000.002: --- NVIM STARTED ---
