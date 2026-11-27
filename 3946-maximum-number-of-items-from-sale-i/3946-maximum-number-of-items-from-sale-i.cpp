namespace rs = std::ranges;
namespace vs = std::views;
namespace {
constexpr auto kMaxNum{std::numeric_limits<int>::max()};
constexpr auto kFactorIdx{0uz};
constexpr auto kPriceIdx{1uz};
constexpr auto getFacor{[] [[nodiscard]] (
        std::vector<int> const & factorAndPrice_
    ) noexcept {
        return factorAndPrice_[kFactorIdx];
    }
};
constexpr auto getPrice{[] [[nodiscard]] (
        std::vector<int> const & factorAndPrice_
    ) noexcept {
        return factorAndPrice_[kPriceIdx];
    }
};
[[maybe_unused]]
auto const fastIOInit{
    [] {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        return 0;
    } ()
};
} 
class Solution final {
public:
    [[nodiscard]]
    static auto maximumSaleItems(
        std::vector<std::vector<int>> const & factorAndPricePerItem_,
        int const budget_
    ) -> int; 
};
auto Solution::maximumSaleItems(
    std::vector<std::vector<int>> const & factorAndPricePerItem_,
    int const budget_
) -> int {  
    if(factorAndPricePerItem_.empty() || budget_ <= 0) {
        return 0;
    }
    auto pricesVs{factorAndPricePerItem_ | vs::transform(getPrice)};
    const auto minPrice{rs::min(pricesVs)};
    if (minPrice > budget_) {
        return 0;
    }
    auto const isPriceWithinBudget{
        [budget_]
        (const auto factorAndPrice_) {
            const auto price{factorAndPrice_.back()};
            return price <= budget_;
        }
    };
    auto factorAndPricePerItemFilteredVs{
        factorAndPricePerItem_ |
        vs::filter(isPriceWithinBudget)
    };
    auto const updateDpItemCnt{
        [budget_, &factorAndPricePerItem_]
        (auto dpItemCnts_, const auto & factorAndPriceThis_) {
            const auto priceThis{factorAndPriceThis_.back()};
            const auto factorThis{factorAndPriceThis_.front()};
            auto const isFreeCopyAvailable{
                [factorThis = factorAndPriceThis_.front()]
                (const auto  factorOther_) {
                    return factorOther_ % factorThis == 0;
                } 
            };
            auto factorOtherVs{factorAndPricePerItem_ | vs::transform(getFacor)};
            const auto itemCnt{static_cast<int>(rs::count_if(
                factorOtherVs,
                isFreeCopyAvailable   
            ))};
            for(auto const price: vs::iota(priceThis, budget_ + 1) | vs::reverse) {
                dpItemCnts_[price] = std::max(
                    dpItemCnts_[price],
                    dpItemCnts_[price - priceThis] + itemCnt
                );
            }
            return dpItemCnts_;
        }
    };
    const auto dpItemCnts{rs::fold_left(
        factorAndPricePerItemFilteredVs,
        std::vector<int>(budget_ + 1),
        updateDpItemCnt
    )};
    auto budgetRng{vs::iota(0, budget_ + 1)};
    auto const calcMaxItemCnt{
        [budget_, minPrice, &dpItemCnts]
        (const auto itemCnt_, const auto price_) {
            const auto itemCntResidual{(budget_ - price_) / minPrice};

            return std::max(itemCnt_, dpItemCnts[price_] + itemCntResidual);
        }
    };
    auto const maxItemCnt{rs::fold_left(budgetRng,0, calcMaxItemCnt)};
    return maxItemCnt;
}